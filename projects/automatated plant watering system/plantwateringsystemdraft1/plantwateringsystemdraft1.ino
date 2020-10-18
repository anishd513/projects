#include <stdint.h>
#include "TouchScreen.h"
#include <TroykaDHT.h>

#include <BH1750FVI.h>

// Create the Lightsensor instance
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

DHT dht(9, DHT11);



#include <LiquidCrystal.h>
int temp=10;
const int sensor_pin=A0;
int sensor_analog=0;
int moisture=9;
int light=8;
int contrast=100;
float temp1=0,moisture1=0,light1=0,humidity1=0;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  LightSensor.begin()  ;
  dht.begin();
  Serial.begin(9600);
  pinMode(temp,INPUT);
  pinMode(moisture,INPUT);
  //pinMode(light,INPUT);
  lcd.begin(16,2);
  analogWrite(6,contrast);

}

void loop() {dht.read();
uint16_t lux = LightSensor.GetLightIntensity();
temp1=dht.getTemperatureC();
humidity1=dht.getHumidity();
sensor_analog = analogRead(sensor_pin);
moisture1 = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
//light1=digitalRead(light);
Serial.print("temp");
Serial.println(temp1);
Serial.print("moisture");
Serial.println(moisture1);
Serial.print("light intensity");
Serial.println(lux);
Serial.print("humididty");
Serial.println(humidity1);
lcd.setCursor(0,0);
lcd.print("c:");
lcd.print(temp1);
lcd.setCursor(0,1);
lcd.print("H20:");
lcd.print(moisture1);
lcd.setCursor(8,0);
lcd.print("LIGHT:");
lcd.print(lux);
lcd.setCursor(9,2);
lcd.print("hum");
lcd.print(humidity1);
delay(2000);
}
