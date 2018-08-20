int sensorAnalogPin = A0;    // select the input pin for the potentiometer
int sensorDigitalPin =8;     

int sensorValue = 0;  // variable to store the value coming from the sensor


// you can adjust the threshold value
int thresholdValue = 800;



void setup()
{
  pinMode(sensorAnalogPin, INPUT);
  pinMode(sensorDigitalPin, INPUT);
  
  Serial.begin(9600);  
}


void loop() 
{
 sensorValue = analogRead(sensorAnalogPin);  // read the value from the sensor:  
 delay(1000);          
 Serial.print("sensor = " );                       
 Serial.println(sensorValue);  


  sensorValue = map(sensorValue,550,0,0,100);

   Serial.print("Mositure : ");
   Serial.print(sensorValue);
   Serial.println("%");

  if(sensorValue < thresholdValue){
    Serial.println(" - Doesn't need watering");
  }
  else {
    Serial.println(" - Time to water your plant");
  }


  if(digitalRead(sensorDigitalPin) == HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  } 
  else 
  {
     digitalWrite(LED_BUILTIN, LOW);
  }

  delay (1000);
}
