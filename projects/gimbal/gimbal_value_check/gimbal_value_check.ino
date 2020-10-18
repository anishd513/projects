int x=90-60;
int testx=0;
void setup() {Serial.begin(115200);
testx=map(x,0,180,180,0);  // put your setup code here, to run once:
Serial.println(x);
Serial.println(testx);
}

void loop() {
  // put your main code here, to run repeatedly:

}
