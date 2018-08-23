/*
DIGITAL ACTUATOR CHECK FOR LED

Connect the -(short leg) of the LED  to GND on the Arduino
Connect the +(long leg) of the LED with resistor to Digital Pin 2 on the Arduino 
*/

int ledPin= 2; 	
boolean ledValue;


/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
      // Setup the connection speed to Serial Monitor and Arduino Board
      // 9600 bits of data per second
      Serial.begin(9600);

      // Pin 2 defined for OUTPUT
      pinMode(ledPin, OUTPUT);

      // Print the output on the Serial Monitor
      Serial.println("DIGITAL ACTUATOR CHECK FOR LED");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
        if ( getLedStatus(ledPin)== true)
          setLedStatus(ledPin, false);
        else
          setLedStatus(ledPin, true);
        // Delay of 1 sec
        delay(1000);
} 

/*********** Digital Write function*********/
void setLedStatus(int ledPin, boolean ledValue)
{  	
    digitalWrite(ledPin, ledValue);
}

/*********** Digital Read function*********/
boolean getLedStatus(int ledPin)
{    
         return (boolean)digitalRead(ledPin);
}


