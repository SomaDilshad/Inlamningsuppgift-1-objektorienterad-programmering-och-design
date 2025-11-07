 #ifndef SENSOR_H
 #define SENSOR_H
 
 #include <string>
 #include <random>
 #include "measurement.h"
 
 class Sensor {
 private:
     // Medlemsvariabler - privata för inkapsling
     std::string namn;
     std::string enhet;
     double minVärde;
     double maxVärde;
     std::string sensorTyp;
     
     // Slumpgenerator - mutable så den kan ändras även i const-metoder
     mutable std::mt19937 generator;
     std::uniform_real_distribution<double> distribution;
 
 public:
     // Konstruktor
     Sensor(const std::string& namn, const std::string& enhet, 
            double minVärde, double maxVärde, const std::string& typ);
     
     // Metoder
     double läsVärde() const;              // Returnerar slumpat värde
     Measurement skapaMätning() const;     // Skapar komplett mätning
     
     // Get-metoder - const eftersom de inte ändrar objektet
     std::string hämtaNamn() const { return namn; }
     std::string hämtaEnhet() const { return enhet; }
     std::string hämtaTyp() const { return sensorTyp; }
 };
 
 #endif

