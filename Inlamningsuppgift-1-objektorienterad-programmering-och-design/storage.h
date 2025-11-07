 #ifndef STORAGE_H
 #define STORAGE_H
 
 #include <vector>
 #include <string>
 #include "measurement.h"
 
 class MeasurementStorage {
 private:
     std::vector<Measurement> mätningar;  // Håller alla mätningar
 
 public:
     // Grundläggande operationer
     void läggTillMätning(const Measurement& mätning);
     void rensaAllaMätningar();
     
     // Statistik - const eftersom de inte ändrar lagringen
     void visaAllaMätningar() const;
     void visaStatistikPerSensor() const;
     void visaStatistikFörSensor(const std::string& sensorNamn) const;
     
     // Filhantering
     bool sparaTillFil(const std::string& filnamn) const;
     bool laddaFrånFil(const std::string& filnamn);
     
     // Hjälpmetoder för statistik
     std::vector<Measurement> hämtaMätningarFörSensor(const std::string& sensorNamn) const;
     int antalMätningarFörSensor(const std::string& sensorNamn) const;
     double beräknaMedelvärde(const std::string& sensorNamn) const;
     double hittaMinVärde(const std::string& sensorNamn) const;
     double hittaMaxVärde(const std::string& sensorNamn) const;
     double beräknaStandardavvikelse(const std::string& sensorNamn) const;
 };
 
 #endif

