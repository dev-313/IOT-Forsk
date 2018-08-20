
/*
DHT22 HUMIDITY SENSOR

Connect the Pin 1 of the DHT22 to GND on the Arduino
Connect the Pin 2 of the DHT22 to +5V on the Arduino
Connect the Pin 3 of the DHT22 to A3 on the Arduino

*/

/* Include the library for using the DHT Sensor of Adafruit Unified Library */
#include <DHT.h>

/* 
Define the Pin of Humidity Sensor LDR 
which is attached to A3 on Arduino
*/
int dht22Pin= A3; 	

/* Global Varibales to store the humidity value */
float humidity;

/* Global Varibales to store the humidity value */
float temperature;

/* Global Variable to access the library functions */
DHT dht22(dht22Pin, DHT22);

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
      pinMode(dht22Pin, INPUT); 
      
      // Print the output on the Serial Monitor
      Serial.println("DHT22 HUMIDITY AND TEMPARATURE SENSOR");
      
      dht22.begin();
}

/*
This function is called in a loop again and again by Arduino infinitely 
untill the RED RESET button is not pressed
*/
void loop()
{
        // Call the function to get the sensor value and store in our global variable
        humidity = dht22.readHumidity();

        // Call the function to get the sensor value and store in our global variable
        temperature = dht22.readTemperature();
        
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

/*
      DHT22 Sensor 
      
      Humidity Range: 0-100% RH
      Humidity Accuracy: ±2-5% RH
      Temperature Range: -40 - 125 °C
      Temperature Accuracy: ±0.5% °C
      Operating Voltage: 3V to 5.5V

*/ 




