 #ifndef MEASUREMENT_H
 #define MEASUREMENT_H

 #include <string>
 #include <chrono>

 // Struktur för att representera ett mätvärde
 struct Measurement {
     std::string sensorNamn;  // Vilken sensor som tagit mätningen
     std::string enhet;       // Enhet för mätvärdet (t.ex. "°C", "%")
     double värde;           // Det faktiska mätvärdet
     std::string tidsstämpel; // När mätningen togs
 
     // Konstruktorer
     Measurement(const std::string& namn, const std::string& enhet, double värde);
     Measurement(const std::string& namn, const std::string& enhet, double värde, const std::string& tid);
 };
 
 #endif

