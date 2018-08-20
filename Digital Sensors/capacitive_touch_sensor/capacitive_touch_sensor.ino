//defining the pin 4 as a input from the sensor 
// ie. sensor output will be connected to this pin

const int touchPin = 4;
boolean touchState;

void setup () 
{
  Serial.begin(9600);
  pinMode (LED_BUILTIN, OUTPUT);
  pinMode (touchPin, INPUT); 
}

void loop () 
{
  
  touchState = getTouchValue(touchPin);
  if (touchState == HIGH) 
  {
    digitalWrite (LED_BUILTIN, HIGH);
    Serial.println("touched");
  }
  else 
  {
  digitalWrite (LED_BUILTIN, LOW);
  Serial.println("not touched");
  }

  delay (1000);
}

boolean getTouchValue(int touchPin)
{
  return (boolean) digitalRead (touchPin);
}
