/*
DIGITAL SENSOR CHECK FOR 3 DIGITAL SENSORS

Connect the + on the sensor board to +5V on the Arduino
Connect the - on the sensor board to GND on the Arduino

Connect the R on the board to Digital Pin 2 on the Arduino 
*/

/* 
Define the Pins on which the sensors are attached
Reed Sensor R is attached to Digital Pin 2 on Arduino
*/

int reedPin= 2;   
/* Global Varibales to store the reed status value */
boolean reedStatus;

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
      pinMode(reedPin, INPUT);

      // Print the output on the Serial Monitor
      Serial.println("REED SENSOR");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
        // Call the function to get the power status and store in our global variable
        reedStatus = getReedStatus(reedPin);
               
        // Print the output on the Serial Monitor
        Serial.println("");
        Serial.println("******************************");
        
        
        Serial.print("Gate Status =  ");
        
        if(reedStatus == true)
                Serial.println("OPEN");

        if(reedStatus == false)
                Serial.println("CLOSE");

        Serial.println("******************************");
        Serial.println("");
        
        // Delay of 1 sec to take the sensor value again
        delay(1000);
} 

/*********** Digital Read function*********/
boolean getReedStatus(int reedPin)
{   
        return (boolean)digitalRead(reedPin);        
}

