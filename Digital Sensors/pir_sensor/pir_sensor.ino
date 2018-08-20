/*
DIGITAL SENSOR CHECK FOR 3 DIGITAL SENSORS

Connect the + on the sensor board to +5V on the Arduino
Connect the - on the sensor board to GND on the Arduino

Connect the X on the board to Digital Pin 4 on the Arduino 
*/

/* 
Define the Pins on which the sensors are attached
PIR Sensor X is attached to Digital Pin 4 on Arduino
*/
int pirPin= 4;   

/* Global Varibales to store the pir status value */
boolean pirStatus;

/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
      // Setup the connection speed to Serial Monitor and Arduino Board
      // 9600 bits of data per second
      Serial.begin(9600);
    
      // Pin 4 defined for taking INPUT
      pinMode(pirPin, INPUT);

      // Print the output on the Serial Monitor
      Serial.println("PIR SENSOR");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
        // Call the function to get the power status and store in our global variable
        pirStatus = getPirStatus(pirPin);
               
        // Print the output on the Serial Monitor
        Serial.println("");
        Serial.println("******************************");
        
        
        Serial.print("Person Status =  ");

        if(pirStatus == true)
                Serial.println("YES");

        if(pirStatus == false)
                Serial.println("NO");
 
        Serial.println("******************************");
        Serial.println("");
        
        // Delay of 1 sec to take the sensor value again
        delay(1000);
} 


boolean getPirStatus(int pirPin)
{    
        return (boolean)digitalRead(pirPin);      
}


