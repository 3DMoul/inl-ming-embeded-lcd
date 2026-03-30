wokwi lcd simulation: https://wokwi.com/projects/455692075285499905

Använde structs för varje företag för att spara info om dem vad dem heter samt hur mycket dem betalade
sen använder jag den informationen till att calculera vilken percent som dem kommer vissas med formeln
100*(vad_dem_betala/summan_av_alla_betalningar)

Använde en switch istället för en if else statements pgv repetivitet det blir bara simplare med switch

jag lägger in percenten för varje företag in i probobility functionen som som tar freqvensen och tar fram företag som har betalat mer oftare och företag som har betalat mindre mer sällan

i början av varje reklam function började jag en while loop som går i 20 sekunder och får current millis på två olika variabler en som inte förendras som är mer som en referens och den som updateras varje loop så oavset hur långt pogramet har gåt så kommer man få exakt 20 sekunder per företags reklam

