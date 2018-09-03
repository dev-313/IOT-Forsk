/*

    URL to Check the Data on Cloud using sylvesterf as Author and Channel ID 223662 
once you have successfully run the project and able to see the data sent from the 
serial monitor 
 
  https://thingspeak.com/channels/223662


    
    GND               0
    o     o     o     o
    GND   IO2   IO0   RX
               
                  
                   
    TX    CH    RST   VCC
    o     o     o     o
    1     3.3         3.3


  ARDUINO      ESP8266
  +3.3V           VCC
  +3.3V           CH_PD
  RXD             RXD  (PIN 0 )
  TXD             TXD  (PIN 1 ) 
  GND             GND
  GND             GPIO0

In order to allow uploading code to the device, we need to guarantee that the ESP8266 starts in flashing mode. 
To do so, we need to connect its GPIO0 pin to GND and CH_PD to 3.3 V before powering it.
Once it is powered up, we can now remove the GPIO pin and then we upload the code to the esp8266
When we have to upload the code, the GPIO0 pin should NOT be connected to GND.
 
 */


#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

#define WIFI_NAME "anto"
#define WIFI_PASSWORD "21122112"
#define server "api.thingspeak.com"
#define apiKey "J0WJOEXGJNF0QNC8"
#define mobile "9928492120"

String uri="/update?api_key="+String(apiKey);
String data="";
String payload ="";
int httpCode;


void setup() 
{
 
  Serial.begin(115200);                                  //Serial connection
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) 
  {  
    //Wait for the WiFI connection completion
    delay(500);
    Serial.println("Waiting for connection");
  }
 
}
 
void loop() 
{
 
 if(WiFi.status()== WL_CONNECTED)
 {   
    //Check WiFi connection status
 
    HTTPClient http;    //Declare object of class HTTPClient

    http.begin(String("http://")+String(server)+String(uri));      //Specify request destination
    http.addHeader("Content-Type", "application/json");  //Specify content-type header

    data = "";
    data += "{";
    data += "\"field1\":\""+String(22.4)+"\",";       // Temperature 
    data += "\"field2\":\""+String(260)+"\",";        // Light
    data += "\"field3\":\""+String(31)+"\",";         // Humidity   
    data += "\"field4\":\""+String(1)+"\",";          // Door Status ( OPEN=1 or CLOSE=0)
    data += "\"field5\":\""+String(0)+"\",";          // Power Status ( ON=1 or OFF=0 )
    data += "\"field6\":\""+String(0)+"\",";          // Person Status ( YES=1 or NO=0 )    
    data += "\"field7\":\""+String(mobile)+"\",";     // Unique ID
    data += "\"field8\":\""+String(mobile)+"\"";      // Mobile number
    data += "}";


 
    httpCode = http.POST(data);   //Send the request
    payload = http.getString();                  //Get the response payload
 
    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
 
    http.end();  //Close connection
 
 }
 else
 {
    Serial.println("Error in WiFi connection");   
 }
  delay(30000);  //Send a request every 30 seconds 
}
