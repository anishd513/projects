/*
  This example uses only 4 wires to test the BH1750 Light sensor
  
  Connecting the sensor to a NodeMCU ESP8266:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> D2
  SCL  <-> D1

  Connecting the sensor to a Arduino UNO:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> A4/SDA 
  SCL  <-> A5/SCL

  Connecting the sensor to a Arduino DUE:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> D20/SDA
  SCL  <-> D21/SCL
*/

#include <BH1750FVI.h>

// Create the Lightsensor instance
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

void setup() 
{
  Serial.begin(9600);
  LightSensor.begin();  
}

void loop()
{
 uint16_t lux = LightSensor.GetLightIntensity();
  //Serial.print("Ligh16_t ");
  Serial.println(lux);
  delay(250);
  if(lux==0)
  {Serial.println("max");
  }
  else if(lux<50&&lux>0)
  {Serial.println("medium");}
  else
  {Serial.println("low");
    }
}
