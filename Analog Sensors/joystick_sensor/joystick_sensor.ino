
int xSensorPin = A1;
int ySensorPin = A0;
int buttonSelectPin = 2;

int xPositionValue = 0;
int yPositionValue = 0;
int buttonState = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);  
  pinMode(xSensorPin, INPUT);
  pinMode(ySensorPin, INPUT);
  //activate pull-up resistor on the push-button pin
  pinMode(buttonSelectPin, INPUT_PULLUP);   
}


void loop() 
{

  readJoystickValue(xSensorPin,ySensorPin,buttonSelectPin);
  
  Serial.print("X: ");
  Serial.print(xPositionValue);
  Serial.print(" | Y: ");
  Serial.print(yPositionValue);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(100); // add some delay between reads
}

void readJoystickValue(int xSensorPin, int ySensorPin, int buttonSelectPin)
{
  xPositionValue = analogRead(xSensorPin);
  yPositionValue = analogRead(ySensorPin);
  buttonState = digitalRead(buttonSelectPin);
}
