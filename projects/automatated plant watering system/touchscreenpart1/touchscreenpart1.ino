#include <TouchScreen.h>
void screenrepeat(int x,int y,float light1,float moisturea,float moistureb, float temp1);
void display_cal(float moisturea1,float moisturea2,float light1,float temp1);
#include <TroykaDHT.h>
DHT dht(11, DHT11);
float moisturea1;
char lux1[10];
float moistureb1;
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
float light1=0;
 char light2[10];
 char moisturea2[10];
  char moistureb2[10];
int threshold1=2;
void setup() {
Serial.begin(9600);
Wire.begin();
pinMode(temp,INPUT);
tft.reset();
  dht.begin();
//temp1=dht.getTemperatureC();
uint16_t identifier =tft.readID();
tft.begin(identifier);
tft.fillScreen(BLACK);
pinMode(12,OUTPUT);
//digitalWrite(12,LOW);
}

void loop() { 
  //Serial.read(moisturea1);
//Serial.read(moistureb1);

//dsplay101()
//Serial.println(light1);
Serial.readBytes(lux1,4); //Read the serial data and store in var
  Serial.println(lux1); //Print data on Serial Monitor
  //delay(1000);
  Serial.readBytes(moisturea2,4); //Read the serial data and store in var
  Serial.println(moisturea2); //Print data on Serial Monitor
  //delay(1000);
  Serial.readBytes(moistureb2,4); //Read the serial data and store in var
  Serial.println(moistureb2); //Print data on Serial Monitor
  //delay(1000);
  light1 =(atof(lux1));
   float moisturea=atof(moisturea2) ;
   float moistureb=atof(moistureb2) ;
  //Serial.println(light1);
  dht.read();
  /*digitalWrite(12,HIGH);
  delay(2000);*/
  digitalWrite(12,LOW);
/*float  previoustemp=temp1;
  temp1=dht.getTemperatureC();
  if(previoustemp!=temp1)
  {  display101(moisturea,moistureb,light1,temp1);}
  Serial.println(moisturea);*/
  //display101(moisturea,moistureb,light1,temp1);

TSPoint p = ts.getPoint();
  screenrepeat(p.x,p.y,light1,moisturea,moistureb,temp1);
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.y);
     Serial.print("\tPressure = "); Serial.println(p.z);
  screenrepeat(p.x,p.y,light1,moisturea,moistureb,temp1);
  }
  }
void screenrepeat(int x,int y, float light1,float moisturea,float moistureb,float temp){
  
tft.reset();

dht.read();
//temp1=dht.getTemperatureC();
humidity1=dht.getHumidity();
uint16_t identifier =tft.readID();
tft.begin(identifier);
tft.fillScreen(BLACK);
/*tft.setCursor(20,50);
tft.setTextSize(2);
tft.print("moisture sensor a");
tft.print(moisturea);
tft.print("moisture sensor b");
tft.print(moistureb);*/

tft.drawRect(5,10,50,100,WHITE);
tft.fillRect(5,10,50,100,RED);
tft.drawRect(65,10,50,100,WHITE);
tft.fillRect(65,10,50,100*(moisturea/330),GREEN);
tft.drawRect(125,10,50,100,WHITE);
tft.fillRect(125,10,50,100*(moistureb/330),MAGENTA);
tft.drawRect(185,10,50,100,WHITE);
tft.fillRect(185,10,50,50,YELLOW);
tft.fillRect(0,220,120,100,RED);
tft.setTextSize(2);
tft.setCursor(30,240);
tft.print("coffee");
tft.fillRect(120,220,120,50,CYAN);
tft.setCursor(155,240);
tft.print("tea");
tft.fillRect(0,270,120,50,CYAN);
tft.setCursor(30,290);
tft.print("rice");
tft.fillRect(120,270,120,50,RED);
tft.setCursor(155,290);
tft.print("wheat");
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
tft.print("mode");
tft.print(threshold1);
tft.setCursor(5,190);
if((200<x)&&(x<500)&&((340<y)&&(y<480)))
{
 threshold1 =((temp1>28)&&(light1>500)&&((moisturea/330)>0.5)&&((moistureb/330)>0.5)&&(humidity1>50));Serial.println("coffee");
while(threshold1){digitalWrite(12,HIGH);}
if(!threshold1){digitalWrite(12,LOW);}
}
 else if((560<x)&&(x<870)&&((340<y)&&(y<480)))
{
  threshold1 =2;
  Serial.println("tea");
 while(threshold1){ digitalWrite(12,HIGH);delay(2000);threshold1=0;}
}
 if((200<x)&&(x<500)&&(((220<y)&&(y<380))))
{
threshold1 =3;Serial.println("rice");
}

else if((540<x)&&(x<890)&&(230<y)&&(y<380))
{
 threshold1 =4;Serial.println("rice");
}

tft.print("threshold:");
tft.print(threshold1);
//tft.setTextColor(RED);
}
void display101(float moisturea,float moistureb,float light1,float temp1){
tft.reset();
//------
dht.read();
temp1=dht.getTemperatureC();
humidity1=dht.getHumidity();
uint16_t identifier =tft.readID();
tft.begin(identifier);
//tft.fillScreen(BLACK);
tft.setCursor(20,50);
//---------
/*tft.setTextSize(2);
tft.print("moisture sensor a");
tft.print(moisturea);
tft.print("moisture sensor b");
tft.print(moistureb);
*/
//----------
tft.fillScreen(BLUE);
tft.drawRect(5,10,50,100,WHITE);
tft.fillRect(5,10,50,100,RED);
tft.drawRect(65,10,50,100,WHITE);
tft.fillRect(65,10,50,100*(moisturea/330),GREEN);
tft.drawRect(125,10,50,100,WHITE);
tft.fillRect(125,10,50,100*(moistureb/330),MAGENTA);
tft.drawRect(185,10,50,100,WHITE);
tft.fillRect(185,10,50,50,YELLOW);
tft.fillRect(0,220,120,100,RED);
//-----
tft.setTextSize(2);
tft.setCursor(30,240);
tft.print("cofee");
tft.fillRect(120,220,120,50,CYAN);
tft.setCursor(155,240);
tft.print("tea");
tft.fillRect(0,270,120,50,CYAN);
tft.setCursor(30,290);
tft.print("rice");
tft.fillRect(120,270,120,50,RED);
tft.setCursor(155,290);
tft.print("wheat");
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
tft.print("light: ");
tft.print(light1);
tft.setCursor(5,170);
tft.print("humidity:");
tft.print(humidity1);
tft.setCursor(5,190);
tft.print("mode");
 //Serial.println(temp1);
 } 
 
