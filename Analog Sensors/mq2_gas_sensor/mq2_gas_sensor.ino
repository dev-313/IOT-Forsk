/* Testing MQ-2 GAS sensor with serial monitor
   Suitable for detecting of LPG, i-butane, propane, methane ,alcohol, Hydrogen or smoke
*/
//GAS sensor output pin to Arduino analog A0 pin
const int gasPin = A0; 

// Your threshold value
int sensorThreshold = 400;

void setup() {
  pinMode(gasPin, INPUT);
  Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop() {
  int analogSensor = readMQ2GasSensor(gasPin );
  Serial.print("Raw Sensor Value: ");
  Serial.println(analogSensor);
  
  if (analogSensor > sensorThreshold)
  {
   Serial.println("ALERT DANGER");
   //tone(buzzer, 1000, 200);
  }
  else
  {
  Serial.println("NORMAL NO EMERGENGY");
  //noTone(buzzer);
  }
  
  delay(1000); // Print value every 1 sec.
}

int readMQ2GasSensor(int gasPin )
{
  return (int) analogRead(gasPin);
}

