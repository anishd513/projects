a#include <TouchScreen.h>
void screenrepeat(int x,int y);
#include <TroykaDHT.h>
DHT dht(11, DHT11);
#include <stdint.h>
#include "TouchScreen.h"
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
int x=0;
int y=0;
int temp=11;
float temp1,humidity1;
int light1=0;
int threshold1=2;
void setup() {
Serial.begin(9600);
Wire.begin();
pinMode(temp,INPUT);
  
tft.reset();
  dht.begin();
uint16_t identifier =tft.readID();
tft.begin(identifier);
//tft.background(YELLOW);
}

void loop() { 
//TSPoint p = ts.getPoint();
  //if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    // Serial.print("X = "); Serial.print(p.x);
     //Serial.print("\tY = "); Serial.print(p.y);
     //Serial.print("\tPressure = "); Serial.println(p.z);
  //screenrepeat();
  //}

TSPoint p = ts.getPoint();
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.y);
     Serial.print("\tPressure = "); Serial.println(p.z);
  screenrepeat(p.x,p.y);
  }
//while(!(p.z>0&&p.z<10000)){};
//if (p.z > 10&& p.z < 1000) {Serial.print("inside");
  //   Serial.print("X = "); Serial.print(p.x);
    // Serial.print("\tY = "); Serial.print(p.y);
     //Serial.print("\tPressure = "); Serial.println(p.z);
  //}Serial.print(" not inside");
if(p.z>10&&p.z<1000){if((p.x>0&&p.x<120)&&(p.y>220&&p.y<270)){threshold1=1;}}
//while(!(p.z>10&&p.z<1000)){};
}
void screenrepeat(int x,int y){
  
tft.reset();

dht.read();
temp1=dht.getTemperatureC();
humidity1=dht.getHumidity();
uint16_t identifier =tft.readID();
tft.begin(identifier);
tft.fillScreen(BLACK);
tft.setCursor(20,50);
tft.drawRect(5,10,50,100,WHITE);
tft.fillRect(5,60,50,50,RED);
tft.drawRect(65,10,50,100,WHITE);
tft.fillRect(65,60,50,50,GREEN);
tft.drawRect(125,10,50,100,WHITE);
tft.fillRect(125,60,50,50,MAGENTA);
tft.drawRect(185,10,50,100,WHITE);
tft.fillRect(185,60,50,50,YELLOW);
tft.fillRect(0,220,120,50,RED);
tft.setTextSize(2);
tft.setCursor(30,240);
tft.print("type1");
tft.fillRect(120,220,120,50,CYAN);
tft.setCursor(155,240);
tft.print("type2");
tft.fillRect(0,270,120,50,CYAN);
tft.setCursor(30,290);
tft.print("type3");
tft.fillRect(120,270,120,50,RED);
tft.setCursor(155,290);
tft.print("type4");
tft.setTextColor(WHITE);
tft.setTextSize(1);
//tft.setTextColor(BLACK);
tft.setCursor(5,110);
tft.print("moisture");
tft.setCursor(65,110);
tft.print("level 1");
tft.setCursor(123,110);
tft.print("level 2");
tft.setCursor(185,110);
tft.print("level 3");
tft.setCursor(5,130);
tft.setTextSize(2);
tft.print("temperature:");
tft.print(temp1);
tft.setCursor(5,150);
tft.print("light intensity:");
tft.print(light1);
tft.setCursor(5,170);
tft.print("humidity:");
tft.print(humidity1);
tft.setCursor(5,190);
if((200<x)&&(x<500)&&((340<y)&&(y<480)))
{
 threshold1 =1;Serial.println("type 1");
}
 else if((560<x)&&(x<870)&&((340<y)&&(y<480)))
{
  threshold1 =2;Serial.println("type 2");
}
 if((200<x)&&(x<500)&&(((220<y)&&(y<380))))
{
threshold1 =3;Serial.println("type 3");
}

else if((540<x)&&(x<890)&&(230<y)&&(y<380))
{
 threshold1 =4;Serial.println("type 4");
}

tft.print("threshold:");
tft.print(threshold1);
//tft.setTextColor(RED);
}
