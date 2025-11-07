 #ifndef UTILS_H
 #define UTILS_H
 
 #include <string>
 #include <chrono>
 
 namespace Utils {
     // Genererar aktuell tidsstämpel
    std::string currentTimestamp();
     
     // Formaterar double-värden
    std::string formatDouble(double value, int decimals = 2);
     
     // Användarinput
    int getIntegerInput(const std::string& prompt);
    double getDoubleInput(const std::string& prompt);
     
     // Felhantering
    bool validateFileFormat(const std::string& line);
 }
 
 #endif

