/*
DIGITAL ACTUATOR CHECK FOR LED PWM

Connect the -(short leg) of the LED  to GND on the Arduino
Connect the +(long leg) of the LED with resistor to Digital Pin 2 on the Arduino 
*/

int ledPin= 3; 	// On Pins with ~ support PWM 
int brightness = 0;    // how bright the LED is
int fadeAmount = 3;    // how many points to fade the LED by

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
      Serial.println("DIGITAL ACTUATOR CHECK FOR LED PWM");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
  // set the brightness of pin 9:
  setLedStatus(ledPin, brightness);
 
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  //Serial.println(brightness);
 
  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
    //Serial.println(fadeAmount);
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
} 

/*********** Digital Write function*********/
void setLedStatus(int ledPin, int ledValue)
{  	
    analogWrite(ledPin, ledValue);
    //Serial.println(ledValue);
}



