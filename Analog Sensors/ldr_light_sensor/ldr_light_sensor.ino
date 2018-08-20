/*
LDR LIGHT SENSOR

Connect the Pin 1 of the LDR to GND on the Arduino
Connect the Pin 2 of the LDR to A1 on the Arduino

*/

/* 
Define the Pin of Light Sensor LDR 
which is attached to A1 on Arduino
*/
int lightPin= A0; 	

/* Global Varibales to store the light value */
float light;

/*
This function is called only once in lifetime
Will be called again when the RED RESET button is pressed on the Arduino
*/
void setup()
{
      // Setup the connection speed to Serial Monitor and Arduino Board
      // 9600 bits of data per second
      Serial.begin(9600);

      // Setting the Pin Mode for the Sensor attached, either INPUT or OUTPUT
      pinMode(lightPin, INPUT);    
      
      // Print the output on the Serial Monitor
      Serial.println("LDR LIGHT SENSOR");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
        // Call the function to get the sensor value and store in our global variable
        light = getLight (lightPin);
        
        // Print the output on the Serial Monitor
        Serial.println("");
        Serial.println("******************************");
        
        Serial.print("Light Intensity in Room =  ");
        Serial.print(light);
        Serial.println(" Lumen");

        Serial.println("******************************");
        Serial.println("");

        // Delay of 5 sec to take the sensor value again
        delay(5000);
} 


/*********** Light Intensity Read function*********/
float getLight(int lightPin)
{  	

        // ananlogRead function converts the input voltage range (0 to 5V), to a digital value between (0 to 1023)
        // This is done by a circuit inside the microcontroller called an analog-to-digital converter or ADC. 
        // Read the value from the Analog Pin and store it to an integer variable
        int sensorValue = analogRead(lightPin); 
        Serial.println(sensorValue);  

        // To scale the numbers between 0.0 and 5.0, 
        // divide 5.0 by 1023.0 and multiply that by sensorValue
        // multiply the result with reference milli volts. (1V = 1000mV)
  	    float milliVoltsTemp = sensorValue*(5.0/1023.0)*1000;

        // There will be 1 lumen change for every 10mV of output
  	    return milliVoltsTemp/10;
}

