 #include "measurement.h"
 #include "utils.h"
 #include <iostream>
 
// Konstruktor med automatisk tidsstämpel
Measurement::Measurement(const std::string& name, const std::string& unit, double value)
    : sensorName(name), unit(unit), value(value), 
      timestamp(Utils::currentTimestamp()) {}
 
// Konstruktor med specifik tidsstämpel  
Measurement::Measurement(const std::string& name, const std::string& unit, 
                       double value, const std::string& time)
    : sensorName(name), unit(unit), value(value), timestamp(time) {}

