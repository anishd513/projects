
 #define datain A0
 #define ledPin 9

 unsigned int temp = 0;
 const unsigned int upperThreshold = 400;
 const unsigned int lowerThreshold = 50;

 void setup()
 {Serial.begin(74880);
   pinMode(ledPin, OUTPUT);
 }

 void loop(){
   temp=analogRead(datain);
   Serial.println(temp);
    if(temp<lowerThreshold)
    {
     digitalWrite(ledPin, LOW);
    }
   
   else if(temp>upperThreshold)
   {
     digitalWrite(ledPin, HIGH);
   }
 }
 
