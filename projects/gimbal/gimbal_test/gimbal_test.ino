
#include <BH1750FVI.h>

// Create the Lightsensor instance
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
#include<Servo.h>
Servo ser1;
Servo ser2;
Servo ser3;
int pos=0;
void setup() {Serial.begin(9600);
  LightSensor.begin();  

  ser1.attach(9); 
  ser2.attach(10);
  ser3.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
uint16_t lux = LightSensor.GetLightIntensity();
//  //Serial.print("Ligh16_t ");
//  Serial.println(lux);
//  delay(250);
//  if(lux==0)
//  {Serial.println("max");
//  }
//  else if(lux<50&&lux>0)
//  {Serial.println("medium");}
//  else
//  {Serial.println("low");
//    }


    ///
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    ser1.write(pos);
    ser2.write(pos);
    ser3.write(pos);
    // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    ser1.write(pos);              // tell servo to go to position in variable 'pos'
    ser2.write(pos);
    ser3.write(pos);
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}
