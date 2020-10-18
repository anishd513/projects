#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

static uint32_t oldtime, newtime = 0;
//DateTime now;
//int oldtime;
//int newtime=0;
int time1;
int ir =9;
int state;
float rpm=0;
void setup() { analogWrite(6,Contrast);
     lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ir,INPUT);

}

void loop() {
   lcd.setCursor(0, 0);
     lcd.print("rpm");
    lcd.setCursor(0, 1);
    
     lcd.print(-rpm);
     delay(500);
  oldtime=micros();
 //Serial.println(oldtime);
  state=digitalRead(ir);
   if(!state)
   {
   newtime=micros();
   //Serial.println(newtime);
   }
  time1=newtime-oldtime;
 // Serial.println("time taken:");
  //Serial.println(time1);
  rpm=1*60000000/time1;
  //Serial.println("the rpm of the given wheel is");
  if(newtime==0){Serial.println("rpm is 0");}else{Serial.println(-rpm);}
//delay(1000);


}
