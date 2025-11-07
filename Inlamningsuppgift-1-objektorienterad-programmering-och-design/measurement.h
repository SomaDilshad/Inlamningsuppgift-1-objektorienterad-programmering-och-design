 #ifndef MEASUREMENT_H
 #define MEASUREMENT_H

 #include <string>
 #include <chrono>

// Struktur för att representera ett mätvärde
struct Measurement {
    std::string sensorName;  // Vilken sensor som tagit mätningen
    std::string unit;        // Enhet för mätvärdet (t.ex. "°C", "%")
    double value;            // Det faktiska mätvärdet
    std::string timestamp;   // När mätningen togs

    // Konstruktorer
    Measurement(const std::string& name, const std::string& unit, double value);
    Measurement(const std::string& name, const std::string& unit, double value, const std::string& time);
};
 
 #endif

