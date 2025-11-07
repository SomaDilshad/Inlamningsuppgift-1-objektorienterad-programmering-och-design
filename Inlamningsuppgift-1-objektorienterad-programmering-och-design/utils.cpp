 #include "utils.h"
 #include <iostream>
 #include <sstream>
 #include <iomanip>
 #include <chrono>
 
 namespace Utils {
 
// Genererar aktuell tidsstämpel i format YYYY-MM-DD HH:MM:SS
std::string currentTimestamp() {
     auto nu = std::chrono::system_clock::now();
     auto tid = std::chrono::system_clock::to_time_t(nu);
     
     std::stringstream ss;
     ss << std::put_time(std::localtime(&tid), "%Y-%m-%d %H:%M:%S");
     return ss.str();
 }
 
// Formaterar double-värden med specificerade decimaler
std::string formatDouble(double value, int decimals) {
     std::stringstream ss;
    ss << std::fixed << std::setprecision(decimals) << value;
     return ss.str();
 }
 
// Hämtar integer-input från användaren med felhantering
int getIntegerInput(const std::string& prompt) {
    int value;
     while (true) {
         std::cout << prompt;
        std::cin >> value;
         
         if (std::cin.fail()) {
             std::cin.clear();                   // Rensa felflaggor
             std::cin.ignore(10000, '\n');       // Rensa bufferten
            std::cout << "Invalid input. Please enter an integer.\n";
         } else {
             std::cin.ignore(10000, '\n');       // Rensa resten av raden
            return value;
         }
     }
 }

// Hämtar double-input från användaren med felhantering
double getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
        } else {
            std::cin.ignore(10000, '\n');
            return value;
        }
    }
}

// Validerar att en CSV-rad har minst 4 fält separerade av kommatecken
bool validateFileFormat(const std::string& line) {
    int commas = 0;
    for (char c : line) {
        if (c == ',') commas++;
    }
    return commas >= 3; // timestamp,sensorName,value,unit
}
 
 } // namespace Utils

