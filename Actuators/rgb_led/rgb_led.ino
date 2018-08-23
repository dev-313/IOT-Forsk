/*
DIGITAL ACTUATOR CHECK FOR RGB LED

Connect the GND of the LED  to GND on the Arduino
Connect the RED of the LED  to Digital Pin 11 on the Arduino
Connect the GREEN of the LED  to Digital Pin 10 on the Arduino 
Connect the BLUE of the LED  to Digital Pin 9 on the Arduino
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE



/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
      // Setup the connection speed to Serial Monitor and Arduino Board
      // 9600 bits of data per second
      Serial.begin(9600);

      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);  

      // Print the output on the Serial Monitor
      Serial.println("DIGITAL ACTUATOR CHECK FOR RGB LED");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
      setColor(255, 0, 0);  // red
      delay(1000);
      setColor(0, 255, 0);  // green
      delay(1000);
      setColor(0, 0, 255);  // blue
      delay(1000);
      setColor(255, 255, 0);  // yellow
      delay(1000);  
      setColor(80, 0, 80);  // purple
      delay(1000);
      setColor(0, 255, 255);  // aqua
      delay(1000);
      setColor(75, 0, 130);  // indigo
      delay(1000);
      setColor(255, 255, 255); // white
      delay(1000);
      setColor(0, 0, 0); // black
      delay(1000);
      setColor(255, 20, 147); // pink
      delay(1000); 
} 



void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

