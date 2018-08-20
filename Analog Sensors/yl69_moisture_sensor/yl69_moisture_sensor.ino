// select the input pin for the potentiometer 
int sensorAnalogPin = A0;     

// variable to store the value coming from the sensor
int sensorValue = 0;  

// you can adjust the threshold value
int thresholdValue = 500;

void setup()
{
  pinMode(sensorAnalogPin, INPUT);
  Serial.begin(9600);  
}


void loop() 
{
  sensorValue = readSoilMoisture(sensorAnalogPin);        
  Serial.print("Raw sensor value = " );                       
  Serial.println(sensorValue);  

  if(sensorValue < thresholdValue)
  {
    Serial.println(" - Doesn't need watering");
  }
  else 
  {
    Serial.println(" - Time to water your plant");
  }
  delay (1000);
}

int readSoilMoisture(int sensorAnalogPin)
{
    // read and return the value from the sensor: 
    return (int) analogRead(sensorAnalogPin);
}
/*
  sensorValue = map(sensorValue,550,0,0,100);

  Serial.print("Mositure : ");
  Serial.print(sensorValue);
  Serial.println("%");
*/

