// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
#include<SoftwareSerial.h>

/* Create object named bt of the class SoftwareSerial */ 
SoftwareSerial bt(2,3); /* (Rx,Tx) */
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

const int FLEX_PIN1 = A1;
const int FLEX_PIN2 = A2; 
const int FLEX_PIN3 = A3; 
const int FLEX_PIN4 = A3; // Pin connected to voltage divider output
int halfbend1=0;
int nobend1=0;
int fullbend1=0;
int halfbend2=0;
int nobend2=0;
int fullbend2=0;
int halfbend3=0;
int nobend3=0;
int fullbend3=0;
int halfbend4=0;
int nobend4=0;
int fullbend4=0;
// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor
int gyro=0;
// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup()
{ bt.begin(9600); /* Define baud rate for software serial communication */
  //Serial.begin(9600); /* Define baud rate for serial communication */

  Serial.begin(9600);
  pinMode(FLEX_PIN4, INPUT);
    pinMode(FLEX_PIN1, INPUT);
      pinMode(FLEX_PIN2, INPUT);
        pinMode(FLEX_PIN3, INPUT);
         // Initialize ASK Object
    rf_driver.init(); 
    const char *msg = "TRANSLATOR";
       rf_driver.send((uint8_t *)msg, strlen(msg));
       rf_driver.waitPacketSent();
        delay(3000);
 
 }

void loop()
{
    if (bt.available()) /* If data is available on serial port */
    {gyro=bt.read();
     Serial.write(gyro);
     Serial.println("");
     /* Print character received on to the serial monitor */
    }
  //finger1
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC1 = analogRead(FLEX_PIN1);
  float flexv1 = flexADC1 * VCC / 1023.0;
  float flexr1 = R_DIV * (VCC / flexv1 - 1.0);
  Serial.println("finger1");
  Serial.println("Resistance: " + String(flexr1) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexr1, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr1>4500&&flexr1<7000)
  {halfbend1=1;
  Serial.println("halfbend");}
    else if(flexr1>1000&&flexr1<4000)
  {fullbend1=1;
   Serial.println("fullbend");}
   else if(flexr1>8500&&flexr1<17000)
  {nobend1=1;
   Serial.println("nobend");}
  
   
   
   
   
   //finger2
   // Read the ADC, and calculate voltage and resistance from it
  int flexADC2 = analogRead(FLEX_PIN2);
   int flexv2 = flexADC2 * VCC / 1023.0;
  int flexr2 = R_DIV * (VCC / flexv2 - 1.0);
   Serial.println("finger2");
  Serial.println("Resistance: " + String(flexr2) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
   angle = map(flexr2, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr2>4500&&flexr2<7000)
  {halfbend2=1;
  Serial.println("halfbend");}
    else if(flexr2>1000&&flexr2<4000)
  {fullbend2=1;
   Serial.println("fullbend");}
   else if(flexr2>8500&&flexr2<17000)
  {nobend2=1;
   Serial.println("nobend");}





//finger3
// Read the ADC, and calculate voltage and resistance from it
  int flexADC3 = analogRead(FLEX_PIN3);
   int flexv3 = flexADC3 * VCC / 1023.0;
   int flexr3 = R_DIV * (VCC / flexv3 - 1.0);
    Serial.println("finger3");
  Serial.println("Resistance: " + String(flexr3) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
   angle = map(flexr3, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr3>4500&&flexr3<7000)
  {halfbend3=1;
  Serial.println("halfbend");}
    else if(flexr3>1000&&flexr3<4000)
  {fullbend3=1;
   Serial.println("fullbend");}
   else if(flexr3>8500&&flexr3<17000)
  {nobend3=1;
   Serial.println("nobend");}




//finger4
// Read the ADC, and calculate voltage and resistance from it
  int flexADC4 = analogRead(FLEX_PIN4);
  int flexv4 = flexADC4 * VCC / 1023.0;
  int flexr4 = R_DIV * (VCC / flexv4 - 1.0);
  Serial.println("Resistance: " + String(flexr4) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
   Serial.println("finger4");
   angle = map(flexr4, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr4>4500&&flexr4<7000)
  {halfbend4=1;
  Serial.println("halfbend");}
    else if(flexr4>1000&&flexr4<4000)
  {fullbend4=1;
   Serial.println("fullbend");}
   else if(flexr4>8500&&flexr4<17000)
  {nobend4=1;
   Serial.println("nobend");}

if(halfbend1==1 && halfbend2==1 && halfbend3==1 && halfbend4==1)
{ const char *msg = "food required";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
  //lcd.print("Food required");
}
else if(halfbend1==1 && nobend2==1 && nobend3==1 && nobend4==1)
{ const char *msg = "need medicine";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
  //lcd.print("Need medicine");
}
else if(fullbend1==1 && fullbend2==1 && fullbend3==1 && fullbend4==1)
{
  //lcd.print("Wheelchair required");
   const char *msg = "Wheelchair required";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
}
else if(nobend1==1 && nobend2==1 && nobend3==1 && fullbend4==1)
{ const char *msg = "need water";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
  //lcd.print("Need water");
}
else if(gyro==2)
{
  delay(1000);
  if(gyro==6)
  {
    if(gyro==8)
    {
      if(nobend1==1&& nobend2==1&&nobend3==1&&nobend4==1);
      {
        Serial.println("finger1");
      }
    }
  }
  }
   const char *msg = "help!";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
//else{
//lcd.print("nothing critical");
//}
}
