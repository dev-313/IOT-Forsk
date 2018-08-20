
void setup() 
{
  
//  pinMode (2, INPUT);
/*
   Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. 
 */
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  Serial.println(sensorVal);
  delay(2000);
}
