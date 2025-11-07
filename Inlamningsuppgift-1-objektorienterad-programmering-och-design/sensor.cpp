 #include "sensor.h"
 #include "utils.h"
 #include <random>
 #include <chrono>
 
 // Konstruktor - initierar sensor med slumpgenerator
 Sensor::Sensor(const std::string& namn, const std::string& enhet, 
                double minVärde, double maxVärde, const std::string& typ)
     : namn(namn), enhet(enhet), minVärde(minVärde), 
       maxVärde(maxVärde), sensorTyp(typ) {
     
     // Använd tid som seed för slumpgeneratorn
     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
     generator.seed(seed);
     distribution = std::uniform_real_distribution<double>(minVärde, maxVärde);
 }
 
 // Returnerar ett slumpmässigt värde inom sensorns intervall
 double Sensor::läsVärde() const {
     return distribution(generator);  // Använder distributionen
 }
 
 // Skapar en komplett mätning med tidsstämpel
 Measurement Sensor::skapaMätning() const {
     double värde = läsVärde();
     return Measurement(namn, enhet, värde);  // Returnerar ett Measurement-objekt
 }

