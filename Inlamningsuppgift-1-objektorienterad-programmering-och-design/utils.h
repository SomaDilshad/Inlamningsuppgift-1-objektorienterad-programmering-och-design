 #ifndef UTILS_H
 #define UTILS_H
 
 #include <string>
 #include <chrono>
 
 namespace Utils {
     // Genererar aktuell tidsstämpel
     std::string nuvarandeTidsstämpel();
     
     // Formaterar double-värden
     std::string formateraDouble(double värde, int decimaler = 2);
     
     // Användarinput
     int hämtaIntegerInput(const std::string& prompt);
     double hämtaDoubleInput(const std::string& prompt);
     
     // Felhantering
     bool valideraFilformat(const std::string& rad);
 }
 
 #endif

