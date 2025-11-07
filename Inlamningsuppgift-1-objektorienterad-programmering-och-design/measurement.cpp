 #include "measurement.h"
 #include "utils.h"
 #include <iostream>
 
 // Konstruktor med automatisk tidsstämpel
 Measurement::Measurement(const std::string& namn, const std::string& enhet, double värde)
     : sensorNamn(namn), enhet(enhet), värde(värde), 
       tidsstämpel(Utils::nuvarandeTidsstämpel()) {}
 
 // Konstruktor med specifik tidsstämpel  
 Measurement::Measurement(const std::string& namn, const std::string& enhet, 
                        double värde, const std::string& tid)
     : sensorNamn(namn), enhet(enhet), värde(värde), tidsstämpel(tid) {}

