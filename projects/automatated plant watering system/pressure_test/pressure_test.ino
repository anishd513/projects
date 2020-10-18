#include <TouchScreen.h>

#include <stdint.h>
//#include "TouchScreen".h
#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#define TS_MINX 122
#define TS_MINY 111
#define TS_MAXX 942
#define TS_MAXY 890

#define YP A1  
#define XM A2  
#define YM 7   
#define XP 6   
#define LCD_RESET A4 
#define LCD_CS A3   
#define LCD_CD A2  
#define LCD_WR A1  
#define LCD_RD A0 

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
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
MCUFRIEND_kbv tft;
void setup() {
 Serial.begin(9600);
 tft.reset();
uint16_t identifier =tft.readID();
tft.begin(identifier);
//tft.background(YELLOW);
tft.fillScreen(WHITE);
}

void loop() {
TSPoint p = ts.getPoint();
//tft.reset();
//uint16_t identifier =tft.readID();
//tft.begin(identifier);
//tft.fillScreen(WHITE);
if(p.z>10&&p.z<1000)
{Serial.print("x=");
Serial.print(p.x);
Serial.println("");
Serial.print("y=");
Serial.print(p.y);
Serial.println("");
} 
}
