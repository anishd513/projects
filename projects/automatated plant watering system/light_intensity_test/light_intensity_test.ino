#include <BH1750FVI.h>

#include <Wire.h>
//#include <BH1750.h>
 
 
BH1750FVI lightMeter;
 
 
void setup(){
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println("Running...");
}
 
 
void loop() {
  uint16_t lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}
