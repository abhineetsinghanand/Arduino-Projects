//soundSensor automatically matches to sound//
int soundSensor = A0; //analog Input pin no for soundSensor//
int threshold = 850;
int led1 = 7; // defining led1 pin no//
int led2 = 6; //defining led2 pin no//
int led3 = 5; //defining led3 pin no//

void setup() //function which runs once
{ 
 pinMode (soundSensor, INPUT); 
 pinMode (led1, OUTPUT);
 pinMode (led2, OUTPUT); 
 pinMode (led3, OUTPUT);
 Serial.begin(9600);
}

void loop() //function which repeats
{
 int sensorValue = analogRead(soundSensor); //soundSensor can take analog as
                                                // well as digital inputs, choose as per requirement//

                                                Serial.println(sensorValue);
 if (sensorValue >=threshold) //if sensor value is greater than threshold, then leds will switch on
 {
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led3, HIGH);
  delay(200);
 }
 else
 {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
 }
}
