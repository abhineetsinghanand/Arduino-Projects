#include <ESP8266WiFi.h>
int smoke = D1;

String apiKey = "6SJLM2C9ZYJJ3MJB";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "Teambox4";     // replace with your wifi ssid and wpa2 key
const char *pass =  "@creators4@";
const char* server = "api.thingspeak.com";

WiFiClient client;


 void setup() {
  // put your setup code here, to run once:
pinMode(smoke,INPUT);
Serial.begin(9600);


  Serial.println("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


}


void loop() {
  // put your main code here, to run repeatedly:
int smokedet= digitalRead(smoke);
 Serial.println(smokedet);


  if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
  {

    String postStr = apiKey;
    postStr += "&field1=";
    postStr += smokedet;


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

    Serial.print("sensor ");
    Serial.print(smokedet);

    Serial.println("%. Send to Thingspeak.");
  }
  client.stop();

  Serial.println("Waiting...");

  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);

}
