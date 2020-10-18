int a=9,b=10;
void setup() {
  // put your setup code here, to run once:
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(a,0);
digitalWrite(b,1);
delay(1000);
digitalWrite(a,0);
digitalWrite(b,0);
delay(100);
}
