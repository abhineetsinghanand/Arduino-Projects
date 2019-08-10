int temp_sensor_val = 0;    // to store value from LM35
int tempPin = A0;           // analog pin to connect LM35
float milli_volt = 0;
float temp_in_celsius = 0;
int led1 = 3;
int led2 = 4;
int led3 = 5;
void setup()
{
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  temp_sensor_val = analogRead (tempPin);
  milli_volt = (temp_sensor_val)*(5000/1024) ;  
  temp_in_celsius = milli_volt/10 ;             //in lm35, each centigrade means a 10mV change. 
  Serial.print("The Temperature is ");
  Serial.print(temp_in_celsius);
  Serial.print("*C");
  Serial.println(); 
  delay(1000);
  if (temp_in_celsius < 90)
  {
    digitalWrite(led1 ,LOW);
    digitalWrite(led2 ,LOW);
    digitalWrite(led3 ,LOW);
    Serial.println("ALL LIGHTS ARE OFF!");
    Serial.println();
  }
  if (temp_in_celsius >= 100 && temp_in_celsius <110)
  {
    digitalWrite(led1 ,HIGH);
    digitalWrite(led2 ,LOW);
    digitalWrite(led3 ,LOW);
    Serial.println("1 LIGHT IS ON!");
    Serial.println();
  }
  else if (temp_in_celsius >= 100 && temp_in_celsius < 130)
  {
    digitalWrite(led1 ,HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    Serial.println("2 LIGHTS ARE ON!");
    Serial.println();
  }
  else if (temp_in_celsius >= 130 )
  { 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    Serial.println("3 LIGHTS ARE ON!");
    Serial.println();
   }
   }
