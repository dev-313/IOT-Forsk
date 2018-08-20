
void setup() {
  // put your setup code here, to run once:
//  pinMode (A0, INPUT);
  pinMode (A0, INPUT_PULLUP); // INPUT or OUTPUT or INPUT_PULLUP
  Serial.begin(9600);
  digitalWrite(A0, INPUT_PULLUP); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int raw_val = analogRead(A0);
  
  Serial.print("Raw value of Analog = ");
  Serial.println(raw_val,DEC); // DEC for Decimal / BIN for Binary / HEX for Hexadecimal

  delay(2000);
}
