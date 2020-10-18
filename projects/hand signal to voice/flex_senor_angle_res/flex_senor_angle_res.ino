const int FLEX_PIN1 = A0;
const int FLEX_PIN2 = A1; 
const int FLEX_PIN3 = A2; 
const int FLEX_PIN4 = A3; // Pin connected to voltage divider output
int halfbend1=0;
int nobend1=0;
int fullbend1=0;
int halfbend2=0;
int nobend2=0;
int fullbend2=0;
int halfbend3=0;
int nobend3=0;
int fullbend3=0;
int halfbend4=0;
int nobend4=0;
int fullbend4=0;
// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 47500.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup()
{
  Serial.begin(9600);
  pinMode(FLEX_PIN4, INPUT);
    pinMode(FLEX_PIN1, INPUT);
      pinMode(FLEX_PIN2, INPUT);
        pinMode(FLEX_PIN3, INPUT);
 
 }

void loop()
{//finger1
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN1);
  float flexv = flexADC * VCC / 1023.0;
  float flexr = R_DIV * (VCC / flexv - 1.0);
  Serial.println("Resistance: " + String(flexr) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexr, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr>4500&&flexr<7000)
  {halfbend1=1;
  Serial.println("halfbend");}
    else if(flexr>1000&&flexr<4000)
  {fullbend1=1;
   Serial.println("fullbend");}
   else if(flexr>8500&&flexr<17000)
  {nobend1=1;
   Serial.println("nobend");}
  
   
   
   
   
   //finger2
   // Read the ADC, and calculate voltage and resistance from it
  int flexADC2 = analogRead(FLEX_PIN2);
  flexv = flexADC2 * VCC / 1023.0;
  flexr = R_DIV * (VCC / flexv - 1.0);
  Serial.println("Resistance: " + String(flexr) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
   angle = map(flexr, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr>4500&&flexr<7000)
  {halfbend2=1;
  Serial.println("halfbend");}
    else if(flexr>1000&&flexr<4000)
  {fullbend2=1;
   Serial.println("fullbend");}
   else if(flexr>8500&&flexr<17000)
  {nobend2=1;
   Serial.println("nobend");}





//finger3
// Read the ADC, and calculate voltage and resistance from it
  int flexADC3 = analogRead(FLEX_PIN3);
   flexv = flexADC3 * VCC / 1023.0;
   flexr = R_DIV * (VCC / flexv - 1.0);
  Serial.println("Resistance: " + String(flexr) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
   angle = map(flexr, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr>4500&&flexr<7000)
  {halfbend3=1;
  Serial.println("halfbend");}
    else if(flexr>1000&&flexr<4000)
  {fullbend3=1;
   Serial.println("fullbend");}
   else if(flexr>8500&&flexr<17000)
  {nobend3=1;
   Serial.println("nobend");}




//finger4
// Read the ADC, and calculate voltage and resistance from it
  int flexADC4 = analogRead(FLEX_PIN4);
   flexv = flexADC4 * VCC / 1023.0;
   flexr = R_DIV * (VCC / flexv - 1.0);
  Serial.println("Resistance: " + String(flexr) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
   angle = map(flexr, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
  if(flexr>4500&&flexr<7000)
  {halfbend4=1;
  Serial.println("halfbend");}
    else if(flexr>1000&&flexr<4000)
  {fullbend4=1;
   Serial.println("fullbend");}
   else if(flexr>8500&&flexr<17000)
  {nobend4=1;
   Serial.println("nobend");}


}
