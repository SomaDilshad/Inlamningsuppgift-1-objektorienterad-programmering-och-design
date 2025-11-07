 #include "storage.h"
 #include "utils.h"
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <iomanip>
 #include <cmath>
 #include <algorithm>
 
 // Lägger till en mätning i lagringen
 void MeasurementStorage::läggTillMätning(const Measurement& mätning) {
     mätningar.push_back(mätning);  // Lägger till i vektorn
 }
 
 // Rensar alla mätningar
 void MeasurementStorage::rensaAllaMätningar() {
     mätningar.clear();  // Tömmer vektorn
 }
 
 // Visar alla sparade mätningar
 void MeasurementStorage::visaAllaMätningar() const {
     if (mätningar.empty()) {  // Kolla om vektorn är tom
         std::cout << "Inga mätningar att visa.\n";
         return;
     }
     
     std::cout << "\n=== ALLA MÄTNINGAR ===\n";
     // Range-based for loop - modern C++
     for (const auto& mätning : mätningar) {
         std::cout << mätning.tidsstämpel << " | " 
                   << mätning.sensorNamn << " | " 
                   << Utils::formateraDouble(mätning.värde) << " " 
                   << mätning.enhet << "\n";
     }
 }

 // Visar statistik för alla sensorer
 void MeasurementStorage::visaStatistikPerSensor() const {
     if (mätningar.empty()) {
         std::cout << "Inga mätningar att analysera.\n";
         return;
     }
     
     // Hämta unika sensornamn
     std::vector<std::string> sensorNamn;
     for (const auto& mätning : mätningar) {
         // Kolla om namnet redan finns
         if (std::find(sensorNamn.begin(), sensorNamn.end(), mätning.sensorNamn) == sensorNamn.end()) {
             sensorNamn.push_back(mätning.sensorNamn);  // Lägg till om det inte finns
         }
     }
     
     std::cout << "\n=== STATISTIK PER SENSOR ===\n";
     for (const auto& namn : sensorNamn) {
         visaStatistikFörSensor(namn);
     }
 }

 // Hämtar alla mätningar för en specifik sensor
 std::vector<Measurement> MeasurementStorage::hämtaMätningarFörSensor(const std::string& sensorNamn) const {
     std::vector<Measurement> resultat;
     for (const auto& mätning : mätningar) {
         if (mätning.sensorNamn == sensorNamn) {
             resultat.push_back(mätning);  // Kopiera mätningen
         }
     }
     return resultat;  // Returnera kopian
 }

 // Beräknar medelvärde för en sensor
 double MeasurementStorage::beräknaMedelvärde(const std::string& sensorNamn) const {
     auto sensorMätningar = hämtaMätningarFörSensor(sensorNamn);
     if (sensorMätningar.empty()) return 0.0;
     
     double summa = 0.0;
     for (const auto& mätning : sensorMätningar) {
         summa += mätning.värde;  // Summera alla värden
     }
     return summa / sensorMätningar.size();  // Dela med antal
 }

 // Beräknar standardavvikelse för en sensor
 double MeasurementStorage::beräknaStandardavvikelse(const std::string& sensorNamn) const {
     auto sensorMätningar = hämtaMätningarFörSensor(sensorNamn);
     if (sensorMätningar.size() < 2) return 0.0;  // Behöver minst 2 värden
     
     double medelvärde = beräknaMedelvärde(sensorNamn);
     double summa = 0.0;
     
     // Beräkna summan av kvadrerade avvikelser
     for (const auto& mätning : sensorMätningar) {
         double diff = mätning.värde - medelvärde;
         summa += diff * diff;  // Kvadrera avvikelsen
     }
     
     // Standardavvikelse = sqrt( summa / (n-1) )
     return std::sqrt(summa / (sensorMätningar.size() - 1));
 }

 // Sparar alla mätningar till fil
 bool MeasurementStorage::sparaTillFil(const std::string& filnamn) const {
     std::ofstream fil(filnamn);  // Öppna fil för skrivning
     if (!fil.is_open()) {
         std::cout << "Kunde inte öppna fil: " << filnamn << "\n";
         return false;
     }
     
     // Skriv varje mätning som CSV-rad
     for (const auto& mätning : mätningar) {
         fil << mätning.tidsstämpel << "," 
             << mätning.sensorNamn << "," 
             << mätning.värde << "," 
             << mätning.enhet << "\n";
     }
     
     fil.close();  // Stäng filen
     std::cout << "Sparade " << mätningar.size() << " mätningar till " << filnamn << "\n";
     return true;
 }

 // Laddar mätningar från fil
 bool MeasurementStorage::laddaFrånFil(const std::string& filnamn) {
     std::ifstream fil(filnamn);  // Öppna fil för läsning
     if (!fil.is_open()) {
         std::cout << "Kunde inte öppna fil: " << filnamn << "\n";
         return false;
     }
     
     std::string rad;
     int inlästa = 0;
     
     while (std::getline(fil, rad)) {  // Läs en rad i taget
         if (rad.empty()) continue;    // Hoppa över tomma rader
         
         if (Utils::valideraFilformat(rad)) {
             std::istringstream ss(rad);  // Skapa ström från rad
             std::string tidsstämpel, sensorNamn, enhet, värdeStr;
             double värde;
             
             // Dela upp raden vid kommatecken
             std::getline(ss, tidsstämpel, ',');
             std::getline(ss, sensorNamn, ',');
             std::getline(ss, värdeStr, ',');
             std::getline(ss, enhet, ',');
             
             try {
                 värde = std::stod(värdeStr);  // Konvertera string till double
                 Measurement mätning(sensorNamn, enhet, värde, tidsstämpel);
                 mätningar.push_back(mätning);
                 inlästa++;
             } catch (const std::exception& e) {
                 std::cout << "Fel vid inläsning av rad: " << rad << "\n";
             }
         }
     }
     
     fil.close();
     std::cout << "Laddade " << inlästa << " mätningar från " << filnamn << "\n";
     return inlästa > 0;
 }

