#include<Servo.h>
Servo ser1;
Servo ser2;
Servo ser3;
int pos=90;
void setup() {
ser1.attach(9);
ser2.attach(10);
ser3.attach(11);
ser1.write(pos);
ser2.write(pos);
ser3.write(pos);

}

void loop() {
  // put your main code here, to run repeatedly:

}
