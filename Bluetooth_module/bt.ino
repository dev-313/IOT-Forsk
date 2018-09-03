
/*
 https://play.google.com/store/apps/details?id=project.bluetoothterminal&hl=en

by mightyIT

Hc-05 Pairing Password is 1234


 */
// library for Serial communication if you are using any two digital pin except pin 0 and 1 of arduino
#include <SoftwareSerial.h> 

SoftwareSerial Home(10, 11); // (TX, RX) creating referance for the library

int BluetoothData; // the data given from Computer

void setup() 
{
  Serial.begin(9600);
  Home.begin(9600); // begin communication with the pin rx and tx defined above
  Home.println("HELLO FROM FORSK LAB");
  Home.println("ENTER 1 TO TURN ON LED");
  Home.println("ENTER 0 TO TURN OFF LED");
  digitalWrite(LED_BUILTIN,LOW);
}

void loop()
{
  if (Home.available())  
  {
      // reading the data send by bluetooth
      BluetoothData=Home.read();
      
      if(BluetoothData=='1')
      {   
          // if number 1 pressed ....
          digitalWrite(LED_BUILTIN,HIGH);
          Home.println("LED  ON ! ");
          Serial.println("RECEIVED COMMAND FOR LED ON");
      }
      
      if (BluetoothData=='0')
      {
          // if number 0 pressed ....
          digitalWrite(LED_BUILTIN,LOW);
          Home.println("LED  OFF ! ");
          Serial.println("RECEIVED COMMAND FOR LED OFF");
      }
  }
  delay(100);// prepare for next data ...
}
