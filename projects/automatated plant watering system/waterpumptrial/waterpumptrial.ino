void setup() {
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
//digitalWrite(3,HIGH);
//digitalWrite(5,LOW);
}

void loop() {
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
delay(1000);
}
