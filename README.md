# Inlamningsuppgift-1-objektorienterad-programmering-och-design
Github link: https://github.com/SomaDilshad/Inlamningsuppgift-1-objektorienterad-programmering-och-design

# Projektbeskrivning
Ett C++-baserat system för att simulera, hantera och analysera mätdata från flera sensorer. Systemet simulerar ett IoT-liknande miljöövervakningssystem med stöd för temperatur, luftfuktighet och tryck.

# Snabbstart
Programmet är helt färdigt och körbart direkt - inga ytterligare inställningar krävs!

# Reflektion över Flersensorsystemet

# Mina lärdomar och insikter

# Vad gick bra

Modulär design
- Att dela upp systemet i tydliga klasser med specifika ansvar gjorde koden mycket lättare att underhålla
- Varje klass har ett välavgränsat ansvar: Sensor (simulering), Measurement (data), Storage (lagring/analys)
- Detta underlättade felsökning och testing av varje del separat

C++17 funktionalitet
- `std::chrono` för tidsstämpling var enkel att implementera och mycket effektiv
- `std::vector` automatiskt minneshantering sparade mycket tid och förhindrade minnesläckor
- Const-correctness gjorde koden säkrare och lättare att förstå

Felhantering
- Robust input-validering för användarinteraktion
- Try-catch blocks för filoperationer förhindrar kraschar
- Menysystemet återställer gracefully vid fel

# Utmaningar och lösningar

Initial arkitektur
- Problem: Först tänkte jag ha all logik i main.cpp
- Lösning: Bryta ut funktionalitet i separata klasser efter Single Responsibility Principle
- Resultat: Mycket renare kod och enklare testing

Filhantering
- Problem: CSV-parsing med felaktiga rader
- Lösning: Implementera valideringsfunktion och try-catch för stod()
- Resultat: Programmet kraschar inte vid korrupta datafiler

Statistikberäkningar
- Problem: Standardavvikelse-algoritm för få datapunkter
- Lösning: Lägga till guard clause för n < 2
- Resultat: Matematiskt korrekt beteende

# Viktigaste insikterna

1. RAII är fantastiskt
   - Inget manuellt minneshanteringsstress
   - Vektorer och filströmmar städar upp efter sig själva
   - Mycket färre buggar än med traditionell C-minneshantering

2. Const-correctness är värt besväret
   - Kompilatorn fångar många potentiella buggar
   - Koden blir självdokumenterande
   - Underlättar optimeringar

3. Separation of Concerns sparar tid
   - Kunde arbeta på storage-klassen utan att röra sensor-logiken
   - Enklare att läsa och förstå koden
   - Mindre risk för sidoeffekter

# Vad jag skulle göra annorlunda nästa gång

Tidig planering
- Skissa klassdiagram innan kodning
- Definiera gränssnitt mellan klasser tydligare
- Planera exception handling strategi från början

Testdriven utveckling
- Skriva enkla tester för varje klass parallellt med implementation
- Särskilt för edge cases i statistiken
- Automatiserade tester för fil-I/O

Mer användning av modern C++
- `std::optional` för valfria returvärden
- `std::variant` för olika typer av mätvärden
- Smart pointers för mer komplexa objektrelationer

# Tekniska reflektioner

Prestanda
- `std::vector` är perfekt för denna typ av datamängd
- Kopiering av Measurement-objekt kan optimeras med move semantics
- Fil-I/O är den största flaskhalsen vid mycket data

Skalbarhet
- Nuvarande design klarar tusentals mätningar
- För miljontals mätningar skulle database behövas
- Realtidskrav skulle kräva trådar och lock-free strukturer

# Stolt över

1. Ren kodstruktur
   - Lätt att läsa och förstå
   - Konsekvent namngivning
   - Bra kommentering där det behövs

2. Användarvänligt gränssnitt
   - Intuitiv meny
   - Bra felmeddelanden
   - Tydlig data-presentation

3. Robust felhantering
   - Programmet kraschar inte
   - Återställer gracefully
   - Informerar användaren om problem

# Framtida förbättringar

För nästa inlämning ser jag potential för:
- Arv och polymorfism för olika sensortyper
- Template-baserad storage för generiska datatyper
- Observer pattern för realtidsdatauppdateringar
- Unit tests med Catch2 eller Google Test

# Slutsats

Detta projekt har varit en excellent övning i objektorienterad design och modern C++ programmering. Jag har lärt mig värdet av:

- Tydlig arkitektur före implementation
- Modulär design för underhållbarhet
- Användarcentrerad design även för konsolapplikationer

Känslan av att ha byggt ett fullt funktionellt system från grunden med rena, välstrukturerade klasser är extremt tillfredsställande. Projektet har gett mig ett solidt fundament att bygga vidare på i nästa inlämning med mer avancerad C++ funktionalitet.
