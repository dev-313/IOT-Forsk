/*
DIGITAL SENSOR CHECK FOR ON OFF STATUS

Connect the - on the sensor board to GND on the Arduino
Connect left of the switch on the board to Digital Pin 2 on the Arduino 
*/

/* 
Define the Pins on which the sensors are attached
Switch Sensor  is attached to Digital Pin 2 on Arduino
*/
int buttonPin= D2; 	

/* Global Varibales to store the power status value */
boolean buttonStatus;

/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
      // Setup the connection speed to Serial Monitor and Arduino Board
      // 9600 bits of data per second
      Serial.begin(9600);

      // Pin 2 defined for taking INPUT
      pinMode(buttonPin, INPUT);

      // Print the output on the Serial Monitor
      Serial.println("DIGITAL SENSOR CHECK FOR ON OFF SWITCH");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
        // Call the function to get the power status and store in our global variable
        buttonStatus = getButtonStatus(buttonPin);
        
        // Print the output on the Serial Monitor
        Serial.println("");
        Serial.println("******************************");
        
        
        Serial.print("Button Status =  ");
        
        if(buttonStatus == true)
                Serial.println("ON");

        if(buttonStatus == false)
                Serial.println("OFF");
        
        Serial.println("******************************");
        Serial.println("");
        
        // Delay of 1 sec to take the sensor value again
        delay(1000);
} 

/*********** Digital Read function*********/
boolean getButtonStatus(int buttonPin)
{  	
         return (boolean)digitalRead(buttonPin);
}
