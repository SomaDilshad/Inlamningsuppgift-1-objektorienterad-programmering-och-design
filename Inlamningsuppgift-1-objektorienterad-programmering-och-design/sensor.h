 #ifndef SENSOR_H
 #define SENSOR_H
 
 #include <string>
 #include <random>
 #include "measurement.h"
 
 class Sensor {
 private:
     // Medlemsvariabler - privata för inkapsling
    std::string name;
    std::string unit;
    double minValue;
    double maxValue;
    std::string sensorType;
     
     // Slumpgenerator - mutable så den kan ändras även i const-metoder
     mutable std::mt19937 generator;
     std::uniform_real_distribution<double> distribution;
 
 public:
     // Konstruktor
    Sensor(const std::string& name, const std::string& unit, 
           double minValue, double maxValue, const std::string& type);
     
     // Metoder
    double readValue() const;             // Returnerar slumpat värde
    Measurement createMeasurement() const; // Skapar komplett mätning
     
     // Get-metoder - const eftersom de inte ändrar objektet
    std::string getName() const { return name; }
    std::string getUnit() const { return unit; }
    std::string getType() const { return sensorType; }
 };
 
 #endif

