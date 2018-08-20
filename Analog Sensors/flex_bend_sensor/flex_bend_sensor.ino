/******************************************************************************
Create a voltage divider circuit combining a flex sensor with a 47k resistor.
- The resistor should connect from A0 to GND.
- The flex sensor should connect from A0 to 3.3V
As the resistance of the flex sensor increases (meaning it's being bent), the
voltage at A0 should decrease.
******************************************************************************/
// Pin connected to voltage divider output
const int FLEX_PIN = A0; 

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
// Measured voltage of Ardunio 5V line
const float VCC = 4.98; 

// Measured resistance of 3.3k resistor
// This will change according to the resistor you put 
const float R_DIV = 47500.0; 

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

float resistanceValue;
float angleValue;


void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
}

void loop() 
{
  readFlexValue(FLEX_PIN);
  Serial.println("Resistance: " + String(resistanceValue) + " ohms");
  Serial.println("Bend: " + String(angleValue) + " degrees");
  Serial.println();
  delay(500);
}

void readFlexValue(int FLEX_PIN)
{
   // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * VCC / 1023.0;
  resistanceValue = R_DIV * (VCC / flexV - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  angleValue = map(resistanceValue, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 90.0);
}

