
int potentiometerPin = A0;
float voltage;


void setup() 
{
  // put your setup code here, to run once:
  pinMode (potentiometerPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  voltage = readVoltage(potentiometerPin);
  Serial.print("Mapped Voltage  = ");
  Serial.println(voltage);
  delay(2000);
}


float readVoltage(int potentiometerPin)
{
  // put your main code here, to run repeatedly:
  int raw_val = analogRead(potentiometerPin);
  
  Serial.print("Raw value of Analog = ");
  Serial.println(raw_val);

  return (float) (raw_val*5.0)/1024.0;
}

