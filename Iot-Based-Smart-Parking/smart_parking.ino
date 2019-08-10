#include <ESP8266WiFi.h>
int ir1 = D2;
int ir2 = D3;


String apiKey = "7O0EIOAE9CLFYPQR";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "Teambox4";     // replace with your wifi ssid and wpa2 key
const char *pass =  "@creators4@";
const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  // put your setup code here, to run once:

  pinMode(ir1, OUTPUT);
  pinMode(ir2, OUTPUT);
//  pinMode(ir3, OUTPUT);
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

  int sensor1 = digitalRead(ir1);
  Serial.println(sensor1);
  int sensor2 = digitalRead(ir2);
  Serial.println(sensor2);
  //int sensor3 = digitalRead(ir3);
  //Serial.println(sensor3);

  if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
  {

    String postStr = apiKey;
    postStr += "&field1=";
    postStr += sensor1;
     postStr += "&field2=";
    postStr += sensor2;
    // postStr += "&field3=";
   // postStr += sensor3;


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

    Serial.print("sensor1 ");
    Serial.print(sensor1);
    Serial.print("sensor2 ");
    Serial.print(sensor2);
    //Serial.print("sensor3 ");
    //Serial.print(sensor3);

    Serial.println("%. Send to Thingspeak.");
  }
  client.stop();

  Serial.println("Waiting...");

  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);


}
