int ul=8;
int dl=9;
int ur=10;
int dr=11;
void setup() {Serial.begin(9600);
 pinMode(ul,OUTPUT);
 pinMode(dl,OUTPUT);
 pinMode(ur,OUTPUT);
 pinMode(dr,OUTPUT);
 Serial.println("hello");
 digitalWrite(ul,HIGH);
      digitalWrite(dl,LOW);
       digitalWrite(ur,LOW);
      digitalWrite(dr,LOW);    
      
}

void loop() {
 
// Serial.println(Serial.read());
 while(!Serial.available()==0){
  //delay(1000);
 // Serial.println(Serial.available());
   // Serial.println(Serial.parseInt());
int  t= Serial.parseInt();
    if(t==8)
      {digitalWrite(ul,LOW);
      digitalWrite(dl,HIGH);
       digitalWrite(ur,LOW);
      digitalWrite(dr,HIGH);
      Serial.println("STRAIGHT ");   
      }
      else if(t==2)
      {
     
      digitalWrite(ul,LOW);
      digitalWrite(dl,HIGH);
       digitalWrite(ur,HIGH);
      digitalWrite(dr,LOW);
      Serial.println("DOWN");      
      }
      else if(t==6)
      {digitalWrite(ul,LOW);
      digitalWrite(dl,HIGH);
       digitalWrite(ur,HIGH);
      digitalWrite(dr,LOW);
      Serial.println("RIGHT");      
     }
      else if(t==4)
      {digitalWrite(ul,LOW);
      digitalWrite(dl,HIGH);
       digitalWrite(ur,HIGH);
      digitalWrite(dr,LOW);    
      Serial.println("DOWN"); 
      }
       else if(t==5)
      {digitalWrite(ul,LOW);
      digitalWrite(dl,LOW);
       digitalWrite(ur,LOW);
      digitalWrite(dr,LOW);    
      Serial.println("STOP"); 
      }
 }
    }
