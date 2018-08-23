/*
DIGITAL ACTUATOR CHECK FOR SERVO MOTOR

Connect the RED of the SERVO MOTOR  to 5V on the Arduino
Connect the BROWN of the SERVO MOTOR  to GND on the Arduino
Connect the ORANGE of the SERVO MOTOR  to Digital Pin 9 on the Arduino

*/

#include <Servo.h> 

int servoPin = 9;
Servo servo;

int angle = 0;   // servo position in degrees 

/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
      // Setup the connection speed to Serial Monitor and Arduino Board
      // 9600 bits of data per second
      Serial.begin(9600);

      servo.attach(servoPin); 

      // Print the output on the Serial Monitor
      Serial.println("DIGITAL ACTUATOR CHECK FOR SERVO MOTOR");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo.write(angle); 
    //Serial.println(angle);              
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle); 
    //Serial.println(angle);          
    delay(15);       
  } 
}

