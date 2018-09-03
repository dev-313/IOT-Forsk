
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN  2


const char* ssid     = "OnePlus 5";
const char* password = "password123";

ESP8266WebServer server(80);
 
// Initialize DHT(humidity) sensor 

DHT dht(DHTPIN, DHTTYPE, 11); // 11 works fine for ESP8266
 
float humidity, temp_f;  // Values read from sensor
String webString="";     // String to display
unsigned long previousMillis = 0;        // will store last temp was read
const long interval = 2000;              // interval at which to read sensor
 
void handle_root() {
  server.send(200, "text/plain", "Hello from the weather esp8266, read from /temp or /humidity");
  delay(100);
}
 
void setup(void)
{
 
  Serial.begin(115200);  // Serial connection from ESP-01 via 3.3v ttl cable
  dht.begin();           // initialize temp. sensor

  // Connect to WiFi network
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\rWorking to connect");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("DHT Weather Reading Server");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
  server.on("/", handle_root);
  
  server.on("/temp", [](){  
    gettemperature();       // read sensor
    //webString ="temp";
    webString="Temperature: "+String((int)temp_f)+" F";   
    Serial.println("temp is");
    Serial.println(webString);
    server.send(200, "text/plain",webString );            
  });

  server.on("/humidity", [](){ 
    gettemperature();           // read sensor
    webString="Humidity: "+String((int)humidity)+"%";
    Serial.println("humidity is");
      Serial.println(webString);
    server.send(200, "text/plain",webString );               
  });
  
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void)
{
  server.handleClient();
} 

void gettemperature() {
 
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;   

   
    humidity = dht.readHumidity();          // Read humidity (percent)
    temp_f = dht.readTemperature(true);     // Read temperature as Fahrenheit
    // Check if any reads failed and exit early (to try again).
    if (isnan(humidity) || isnan(temp_f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  }
}
