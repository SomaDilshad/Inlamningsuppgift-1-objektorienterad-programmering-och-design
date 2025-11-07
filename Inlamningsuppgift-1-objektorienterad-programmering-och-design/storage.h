 #ifndef STORAGE_H
 #define STORAGE_H
 
 #include <vector>
 #include <string>
 #include "measurement.h"
 
 class MeasurementStorage {
 private:
    std::vector<Measurement> measurements;  // Håller alla mätningar
 
 public:
     // Grundläggande operationer
    void addMeasurement(const Measurement& measurement);
    void clearAllMeasurements();
     
     // Statistik - const eftersom de inte ändrar lagringen
    void showAllMeasurements() const;
    void showStatisticsPerSensor() const;
    void showStatisticsForSensor(const std::string& sensorName) const;
     
     // Filhantering
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
     
     // Hjälpmetoder för statistik
    std::vector<Measurement> getMeasurementsForSensor(const std::string& sensorName) const;
    int countMeasurementsForSensor(const std::string& sensorName) const;
    double calculateAverage(const std::string& sensorName) const;
    double findMinValue(const std::string& sensorName) const;
    double findMaxValue(const std::string& sensorName) const;
    double calculateStandardDeviation(const std::string& sensorName) const;
 };
 
 #endif

