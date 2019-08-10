// Interfacing DHT11 with Oled
#include <DHT.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include<ESP8266WiFi.h>
Adafruit_SSD1306 oled;

String apiKey = "P43LMFB8VV4PRMA3";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "Teambox4";     // replace with your wifi ssid and wpa2 key
const char *pass =  "@creators4@";
const char* server = "api.thingspeak.com";
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WiFiClient  client;

float temp = 0;
float hum = 0;
void setup() {
  //serial communication with computer you can check by pressing ctrl+shift+M
  pinMode(DHTPIN, INPUT); // pins setup
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.setTextColor(WHITE);
  oled.setTextSize(2);
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.print("Temperature");
  oled.setCursor(0, 15);
  oled.print("And Humidity");
  oled.display();
  Serial.begin(9600); 
  delay(10);
  dht.begin();
  
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid,pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(WiFi.status());
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  
}
void loop()
{ float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(("Failed to read from DHT sensor!"));
    return;
  }

if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
  {

    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(t);
    postStr += "&field2=";
    postStr += String(h);


    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("temperature ");
    Serial.print(t);
    Serial.print("degree celcius, Humidity ");
    Serial.print(h);
    Serial.println("%. Send to Thingspeak.");
      
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.print("Temp:");
  oled.setCursor(60, 0);
//  Serial.print("Temperature = ");
  temp = dht.readTemperature();
  oled.print(temp);
  Serial.println(temp);
  /*oled.setCursor(0, 15);
  oled.print("Humidity:");
  oled.setCursor(80, 15);
  hum = dht.readHumidity();
  Serial.println(h);
  Serial.print(hum);*/
  delay(500); // wait for 1 second
  oled.display();
}

client.stop();

Serial.println("Waitinggg...");

delay(10000);
}
