int led=13;
int sensor=2;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int vib=digitalRead(sensor);
Serial.println(vib);

if(vib==1)
{
digitalWrite(led,HIGH);
Serial.println("vibration detected");

}
else{
digitalWrite(led,LOW);
Serial.println("NOT detected");
}


}
