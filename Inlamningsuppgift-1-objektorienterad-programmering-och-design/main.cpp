 #include <iostream>
 #include <vector>
 #include <memory>
 #include "sensor.h"
 #include "storage.h"
 #include "utils.h"
 
 // Forward-deklarationer av funktioner
 void visaHuvudmeny();
 void läsNyaMätningar(const std::vector<Sensor>& sensorer, MeasurementStorage& lagring);
 void visaSensorStatistik(const MeasurementStorage& lagring);
 void hanteraFiloperationer(MeasurementStorage& lagring);
 
 int main() {
     std::cout << "=== FLERSENSORSYSTEM MED MÄTVÄRDESINSAMLING ===\n";
     
     // Skapa sensorer - använd uniform initialization
     std::vector<Sensor> sensorer = {
         Sensor("TemperaturSensor 1", "°C", 15.0, 30.0, "Temperatur"),
         Sensor("LuftfuktighetSensor 1", "%", 30.0, 80.0, "Luftfuktighet"),
         Sensor("TryckSensor 1", "hPa", 980.0, 1050.0, "Tryck")
     };
     
     MeasurementStorage lagring;  // Skapa lagringsobjekt
     
     int val;
     do {
         visaHuvudmeny();
         val = Utils::hämtaIntegerInput("Välj alternativ: ");
         
         switch (val) {
             case 1:
                 läsNyaMätningar(sensorer, lagring);
                 break;
             case 2:
                 visaSensorStatistik(lagring);
                 break;
             // ... andra cases
             case 0:
                 std::cout << "Avslutar programmet...\n";
                 break;
             default:
                 std::cout << "Ogiltigt val. Försök igen.\n";
         }
         
         if (val != 0) {
             std::cout << "\nTryck på Enter för att fortsätta...";
             std::cin.get();  // Vänta på användaren
         }
         
     } while (val != 0);  // Kör tills användaren väljer 0
     
     return 0;
 }

