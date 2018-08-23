/*
DIGITAL ACTUATOR CHECK FOR RELAY

Connect the GND of the RELAY  to GND on the Arduino
Connect the IN1 of the RELAY  to Digital Pin 10 on the Arduino 
Connect the IN2 of the RELAY  to Digital Pin 11 on the Arduino 
Connect the VCC of the RELAY  to 5V on the Arduino
*/

//the relays connect to
int relayFirstPin = 10;
int relaySecondPin = 11;

#define ON   0
#define OFF  1

/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
      // Setup the connection speed to Serial Monitor and Arduino Board
      // 9600 bits of data per second
      Serial.begin(9600);

      pinMode(relayFirstPin, OUTPUT);
      pinMode(relaySecondPin, OUTPUT);
  
      setRelayStatus(OFF, OFF); //turn off all the relay

      // Print the output on the Serial Monitor
      Serial.println("DIGITAL ACTUATOR CHECK FOR RELAY");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
  //turn on RELAY_1
  setRelayStatus(ON, OFF);

  //delay 2s
  delay(2000);
  
  //turn on RELAY_2
  setRelayStatus(OFF, ON);

  //delay 2s
  delay(2000);
} 

///set the status of relays
void setRelayStatus( unsigned char status_1,  unsigned char status_2)
{
  digitalWrite(relayFirstPin, status_1);
  digitalWrite(relaySecondPin, status_2);
}


