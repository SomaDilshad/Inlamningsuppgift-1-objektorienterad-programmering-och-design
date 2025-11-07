 #include "sensor.h"
 #include "utils.h"
 #include <random>
 #include <chrono>
 
// Konstruktor - initierar sensor med slumpgenerator
Sensor::Sensor(const std::string& name, const std::string& unit, 
               double minValue, double maxValue, const std::string& type)
    : name(name), unit(unit), minValue(minValue), 
      maxValue(maxValue), sensorType(type) {
     
     // Använd tid som seed för slumpgeneratorn
     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
     generator.seed(seed);
     distribution = std::uniform_real_distribution<double>(minVärde, maxVärde);
 }
 
// Returnerar ett slumpmässigt värde inom sensorns intervall
double Sensor::readValue() const {
     return distribution(generator);  // Använder distributionen
 }
 
// Skapar en komplett mätning med tidsstämpel
Measurement Sensor::createMeasurement() const {
    double value = readValue();
    return Measurement(name, unit, value);  // Returnerar ett Measurement-objekt
 }

