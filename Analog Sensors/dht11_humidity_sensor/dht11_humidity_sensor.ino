
/*
DHT11 HUMIDITY SENSOR

Connect the Pin 1 of the DHT11 to +5V on the Arduino
Connect the Pin 2 of the DHT11 to A2 on the Arduino
Connect the Pin 3 of the DHT11 is not used
Connect the Pin 4 of the DHT11 to GND on the Arduino

*/
/* Include the library for using the DHT Sensor */
#include <dht11.h>

/* 
Define the Pin of Humidity Sensor LDR 
which is attached to A2 on Arduino
*/
int dht11Pin= A2; 	

/* Global Varibales to store the humidity value */
float humidity;

/* Global Varibales to store the humidity value */
float temperature;

/* Global Variable to access the library functions */
dht11 myDHTSensor;

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
      pinMode(dht11Pin, INPUT); 
      
      // Print the output on the Serial Monitor
      Serial.println("DHT11 HUMIDITY AND TEMPARATURE SENSOR");
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
        // Call the function to get the sensor value and store in our global variable
        humidity = getDhtHumidity (dht11Pin);

        // Call the function to get the sensor value and store in our global variable
        temperature = getDhtTemperature (dht11Pin);
        
        // Print the output on the Serial Monitor
        Serial.println("");
        Serial.println("******************************");
        
        Serial.print("Humidity in Room =  ");
        Serial.print(humidity);
        Serial.println(" % Relative Humidity");

        Serial.print("Temparature of the Room =  ");
        Serial.print(temperature);
        Serial.println(" degree Celsius");


        Serial.println("******************************");
        Serial.println("");

        // Delay of 5 sec to take the sensor value again
        delay(5000);
} 


/*********** Humidity Read function*********/
float getDhtHumidity(int dht11Pin)
{  	
         // Read the sensor value using the dht library read function 
        myDHTSensor.read(dht11Pin);

        // After reading the value which is stored in the library variable
        return (float)myDHTSensor.humidity;
}

float getDhtTemperature(int dht11Pin)
{    
         // Read the sensor value using the dht library read function 
        myDHTSensor.read(dht11Pin);

        // After reading the value which is stored in the library variable
        return (float)myDHTSensor.temperature;
}


/*
      DHT11 Sensor 
      
      Humidity Range: 20-90% RH
      Humidity Accuracy: ±5% RH
      Temperature Range: 0-50 °C
      Temperature Accuracy: ±2% °C
      Operating Voltage: 3V to 5.5V

*/    



