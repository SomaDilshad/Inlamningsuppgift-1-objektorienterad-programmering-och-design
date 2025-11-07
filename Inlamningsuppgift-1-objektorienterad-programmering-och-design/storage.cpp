 #include "storage.h"
 #include "utils.h"
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <iomanip>
 #include <cmath>
 #include <algorithm>
 
// Lägger till en mätning i lagringen
void MeasurementStorage::addMeasurement(const Measurement& measurement) {
    measurements.push_back(measurement);  // Lägger till i vektorn
 }
 
// Rensar alla mätningar
void MeasurementStorage::clearAllMeasurements() {
    measurements.clear();  // Tömmer vektorn
 }
 
// Visar alla sparade mätningar
void MeasurementStorage::showAllMeasurements() const {
    if (measurements.empty()) {  // Kolla om vektorn är tom
        std::cout << "No measurements to display.\n";
         return;
     }
     
    std::cout << "\n=== ALL MEASUREMENTS ===\n";
     // Range-based for loop - modern C++
    for (const auto& measurement : measurements) {
        std::cout << measurement.timestamp << " | " 
                  << measurement.sensorName << " | " 
                  << Utils::formatDouble(measurement.value) << " " 
                  << measurement.unit << "\n";
     }
 }

// Visar statistik för alla sensorer
void MeasurementStorage::showStatisticsPerSensor() const {
    if (measurements.empty()) {
        std::cout << "No measurements to analyze.\n";
         return;
     }
     
     // Hämta unika sensornamn
    std::vector<std::string> sensorNames;
    for (const auto& measurement : measurements) {
         // Kolla om namnet redan finns
        if (std::find(sensorNames.begin(), sensorNames.end(), measurement.sensorName) == sensorNames.end()) {
            sensorNames.push_back(measurement.sensorName);  // Lägg till om det inte finns
         }
     }
     
    std::cout << "\n=== STATISTICS PER SENSOR ===\n";
    for (const auto& name : sensorNames) {
        showStatisticsForSensor(name);
     }
 }

// Hämtar alla mätningar för en specifik sensor
std::vector<Measurement> MeasurementStorage::getMeasurementsForSensor(const std::string& sensorName) const {
    std::vector<Measurement> result;
    for (const auto& measurement : measurements) {
        if (measurement.sensorName == sensorName) {
            result.push_back(measurement);  // Kopiera mätningen
         }
     }
    return result;  // Returnera kopian
 }

// Beräknar medelvärde för en sensor
double MeasurementStorage::calculateAverage(const std::string& sensorName) const {
    auto sensorMeasurements = getMeasurementsForSensor(sensorName);
    if (sensorMeasurements.empty()) return 0.0;
     
     double summa = 0.0;
    for (const auto& measurement : sensorMeasurements) {
        summa += measurement.value;  // Summera alla värden
     }
    return summa / sensorMeasurements.size();  // Dela med antal
 }

// Beräknar standardavvikelse för en sensor
double MeasurementStorage::calculateStandardDeviation(const std::string& sensorName) const {
    auto sensorMeasurements = getMeasurementsForSensor(sensorName);
    if (sensorMeasurements.size() < 2) return 0.0;  // Behöver minst 2 värden
     
    double medelvärde = calculateAverage(sensorName);
     double summa = 0.0;
     
     // Beräkna summan av kvadrerade avvikelser
    for (const auto& measurement : sensorMeasurements) {
        double diff = measurement.value - medelvärde;
         summa += diff * diff;  // Kvadrera avvikelsen
     }
     
     // Standardavvikelse = sqrt( summa / (n-1) )
    return std::sqrt(summa / (sensorMeasurements.size() - 1));
 }

// Sparar alla mätningar till fil
bool MeasurementStorage::saveToFile(const std::string& filename) const {
    std::ofstream fil(filename);  // Öppna fil för skrivning
    if (!fil.is_open()) {
        std::cout << "Could not open file: " << filename << "\n";
         return false;
     }
     
     // Skriv varje mätning som CSV-rad
    for (const auto& measurement : measurements) {
        fil << measurement.timestamp << "," 
            << measurement.sensorName << "," 
            << measurement.value << "," 
            << measurement.unit << "\n";
     }
     
     fil.close();  // Stäng filen
    std::cout << "Saved " << measurements.size() << " measurements to " << filename << "\n";
     return true;
 }

// Laddar mätningar från fil
bool MeasurementStorage::loadFromFile(const std::string& filename) {
    std::ifstream fil(filename);  // Öppna fil för läsning
    if (!fil.is_open()) {
        std::cout << "Could not open file: " << filename << "\n";
         return false;
     }
     
     std::string rad;
    int readCount = 0;
     
     while (std::getline(fil, rad)) {  // Läs en rad i taget
         if (rad.empty()) continue;    // Hoppa över tomma rader
         
        if (Utils::validateFileFormat(rad)) {
             std::istringstream ss(rad);  // Skapa ström från rad
            std::string timestamp, sensorName, unit, valueStr;
            double value;
             
             // Dela upp raden vid kommatecken
            std::getline(ss, timestamp, ',');
            std::getline(ss, sensorName, ',');
            std::getline(ss, valueStr, ',');
            std::getline(ss, unit, ',');
             
             try {
                value = std::stod(valueStr);  // Konvertera string till double
                Measurement measurement(sensorName, unit, value, timestamp);
                measurements.push_back(measurement);
                readCount++;
             } catch (const std::exception& e) {
                std::cout << "Error reading line: " << rad << "\n";
             }
         }
     }
     
     fil.close();
    std::cout << "Loaded " << readCount << " measurements from " << filename << "\n";
    return readCount > 0;
 }

