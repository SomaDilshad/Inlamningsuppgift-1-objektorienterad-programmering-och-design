 #include "utils.h"
 #include <iostream>
 #include <sstream>
 #include <iomanip>
 #include <chrono>
 
 namespace Utils {
 
 // Genererar aktuell tidsstämpel i format YYYY-MM-DD HH:MM:SS
 std::string nuvarandeTidsstämpel() {
     auto nu = std::chrono::system_clock::now();
     auto tid = std::chrono::system_clock::to_time_t(nu);
     
     std::stringstream ss;
     ss << std::put_time(std::localtime(&tid), "%Y-%m-%d %H:%M:%S");
     return ss.str();
 }
 
 // Formaterar double-värden med specificerade decimaler
 std::string formateraDouble(double värde, int decimaler) {
     std::stringstream ss;
     ss << std::fixed << std::setprecision(decimaler) << värde;
     return ss.str();
 }
 
 // Hämtar integer-input från användaren med felhantering
 int hämtaIntegerInput(const std::string& prompt) {
     int värde;
     while (true) {
         std::cout << prompt;
         std::cin >> värde;
         
         if (std::cin.fail()) {
             std::cin.clear();                   // Rensa felflaggor
             std::cin.ignore(10000, '\n');       // Rensa bufferten
             std::cout << "Ogiltig inmatning. Ange ett heltal.\n";
         } else {
             std::cin.ignore(10000, '\n');       // Rensa resten av raden
             return värde;
         }
     }
 }
 
 } // namespace Utils

