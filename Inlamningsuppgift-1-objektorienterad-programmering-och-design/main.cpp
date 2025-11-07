 #include <iostream>
 #include <vector>
 #include <memory>
 #include "sensor.h"
 #include "storage.h"
 #include "utils.h"
 
// Forward-deklarationer av funktioner (inte använda i denna förenklade version)
 
int main() {
    std::cout << "=== MULTI-SENSOR SYSTEM WITH MEASUREMENT COLLECTION ===\n";

    // Skapa sensorer - använd uniform initialization
    std::vector<Sensor> sensors = {
        Sensor("Temperature Sensor 1", "°C", 15.0, 30.0, "Temperature"),
        Sensor("Humidity Sensor 1", "%", 30.0, 80.0, "Humidity"),
        Sensor("Pressure Sensor 1", "hPa", 980.0, 1050.0, "Pressure")
    };

    MeasurementStorage storage;  // Skapa lagringsobjekt

    // Enkel körning - ingen meny i denna version
    std::cout << "Program started.\n";
    return 0;
}

