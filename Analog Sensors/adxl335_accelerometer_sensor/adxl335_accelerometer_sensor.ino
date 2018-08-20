const int xInputPin = A3;
const int yInputPin = A4;
const int zInputPin = A5;


// Take multiple samples to reduce noise
const int sampleSize = 10;

//The minimum and maximum values that came from
//the accelerometer while standing still
//You very well may need to change these
int minVal = 265;
int maxVal = 402;

//to hold the caculated values
double xSensorValue;
double ySensorValue;
double zSensorValue;

void setup() 
{
  pinMode(xInputPin, INPUT);
  pinMode(yInputPin, INPUT);
  pinMode(zInputPin, INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
    readAccelerometerValue(xInputPin, yInputPin, zInputPin);

    //Output the caculations
    Serial.print("x: ");  
    Serial.print(xSensorValue );
    Serial.print(" | y: ");
    Serial.print(ySensorValue );
    Serial.print(" | z: ");
    Serial.println(zSensorValue );
    delay(500);
}


void readAccelerometerValue(int xInputPin, int yInputPin, int zInputPin)
{
    int xRaw = ReadAxis(xInputPin);
    int yRaw = ReadAxis(yInputPin);
    int zRaw = ReadAxis(zInputPin);

    Serial.println();
    Serial.print(xRaw);
    Serial.print(", ");
    Serial.print(yRaw);
    Serial.print(", ");
    Serial.print(zRaw);
    Serial.println();

    //convert read values to degrees -90 to +90 – Needed for atan2
    int xAng = map(xRaw, minVal, maxVal, -90, 90);
    int yAng = map(yRaw, minVal, maxVal, -90, 90);
    int zAng = map(zRaw, minVal, maxVal, -90, 90);

    //Caculate 360deg values like so: atan2(-yAng, -zAng)
    //atan2 outputs the value of -π to π (radians)
    //We are then converting the radians to degrees
    xSensorValue = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
    ySensorValue = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
    zSensorValue = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);
  
}



// Read "sampleSize" samples and report the average
int ReadAxis(int axisPin)
{
  long reading = 0;
  analogRead(axisPin);
  delay(1);
  for (int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(axisPin);
  }
  return reading/sampleSize;
}

/*
// The accelerometer uses very little current, so it can be plugged into your board and run directly off 
// of the output from the digital output pins.
// pin A0 (equivalent digital pin14) is VCC 
// and pin A4 (equivalent digital pin18) in GND 
// to activate the GY-61-module

pinMode(A0, OUTPUT);
pinMode(A4, OUTPUT);

// to set the A0 to 5V as VCC
digitalWrite(14, HIGH);

// to set the A4 to 0V as GND
digitalWrite(18, LOW);
*/



