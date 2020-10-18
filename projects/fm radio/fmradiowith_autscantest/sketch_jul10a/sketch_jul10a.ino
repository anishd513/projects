
#include <stdint.h>
#include "TouchScreen.h"
#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <TEA5767Radio.h>
#include <TEA5767.h>

//because they use different Hardware-SPI Pins
//SD_SS    connects to digital pin 10
//SD_DI    connects to digital pin 11
//SD_DO    connects to digital pin 12
//SD_SCK   connects to digital pin 13

#define TS_MINX 122
#define TS_MINY 111
#define TS_MAXX 942
#define TS_MAXY 890
// These are the pins for the shield!
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin
#define LCD_CS A3   // Chip Select goes to Analog 3
#define LCD_CD A2  // Command/Data goes to Analog 2
#define LCD_WR A1  // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define MINPRESSURE 10
#define MAXPRESSURE 1000
boolean buttonEnabled=true;
int change=0;
int i=0;
float l=0;
float radio[]={91.1,91.9,92.7,93.5,94.3,95,98.3,101.3,104};
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

TEA5767 radio1 = TEA5767();
MCUFRIEND_kbv tft;
 void setup()
 {Serial.begin(9600);
  radio1.setFrequency(0);
  Wire.begin();
   tft.reset();
   
  uint16_t identifier = tft.readID();
   tft.begin(identifier);
   tft.fillScreen(BLACK);
 tft.setCursor(100,0);
 tft.setTextColor(RED);
 tft.setTextSize(2);
 tft.println("welcome ");
 tft.println("touch screenfm radio");
 tft.println("");
 tft.setCursor(50,50);
 tft.fillRect(0,0,400,200,YELLOW);
 tft.setTextColor(RED);
 
 tft.fillRect(0,350,500,500,BLUE);
  tft.setTextSize(5);
 tft.setCursor(130,70);
 tft.println("+");
 tft.setCursor(130,430);

 tft.println("-");
 tft.setCursor(45,300);
  tft.setTextSize(2);
 tft.println("choose a station");
 //radio1.setFrequency(0);
 }
void loop(void) {
  l=radio1.getFrequency();
    
  
  // a point object holds x y and z coordinates
  TSPoint p = ts.getPoint();
  
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.y);
     Serial.print("\tPressure = "); Serial.println(p.z);
  }
  if(p.z > MINPRESSURE && p.z < MAXPRESSURE) {
      if(p.y>830&&p.y<900)
        {
         Serial.println("decrease");
         change=2;
        }
      
    
      if(p.y>930&&p.y<990)
        {
         Serial.println("increase");
         tft.setCursor(45,300);
         tft.setTextColor(RED);
         change=1;
         tft.println("104");
        }
 if(i==9)
   {
    
    if(change==2) 
    {i--;
    radio[i];
    change=0;
    }
    change=0;
   }
  if(i==0)
   {
    
    if(change==1) 
    {i++; 
    radio1.seekUp();
    change=0; 
   } 
   }
  
 else if(change==1)
    {i++;
    radio[i];
    radio1.seekUp();
    change=0;
    }
  else if(change==2) 
    {i--;

    radio[i];
    change=0;
    } 
  else if(change==0)
  {radio[i];
    }
  
   Serial.println("radio");
   Serial.println(radio[i]);  
   Serial.println(i);
  }
 if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {//radio1.setFrequency(0);
 tft.reset();
 
  uint16_t identifier = tft.readID();

 tft.begin(identifier);
 
 }
 
 tft.fillScreen(BLACK);
 tft.setCursor(100,0);
 tft.setTextColor(RED);
 tft.setTextSize(2);
 tft.println("welcome ");
 tft.println("touch screenfm radio");
 tft.println("");
 tft.setCursor(50,50);
 tft.fillRect(0,0,400,200,CYAN);
 tft.setTextColor(RED);
 
 tft.fillRect(0,350,500,500,BLUE);
  tft.setTextSize(5);
 tft.setCursor(130,70);
 tft.println("+");
 tft.setCursor(130,430);

 tft.println("-");
 tft.setCursor(45,300);
  tft.setTextSize(2);
 tft.println("this is a touchscreen  ");
 tft.setCursor(120,320);
 tft.println("radio");
  tft.setCursor(25,250);
  tft.setTextSize(2);
  tft.print("radio station selected ");
   tft.setCursor(120,270);
 tft.println(l);
 Serial.println(radio[i]);
}
