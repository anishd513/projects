/*
  433 MHz RF Module Receiver Demonstration 1
  RF-Rcv-Demo-1.ino
  Demonstrates 433 MHz RF Receiver Module
  Use with Transmitter Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
#include <LiquidCrystal.h>
int contrast=60;
LiquidCrystal lcd(12,10,5,4,3,2);


void setup() {lcd.begin(16,2);
  Serial.begin(9600);
  analogWrite(6,contrast);
  
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
 }
void loop()
{lcd.setCursor(0,0);
//lcd.print((char*)buf);


    // Set buffer to size of expected message
    uint8_t buf[24];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char*)buf);
   lcd.print((char*)buf);         
    }}
