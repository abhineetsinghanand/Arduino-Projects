
int led=12;
int touch=2;
void setup() 
{
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
int sensor= digitalRead(touch);
if(sensor==1)
{
  digitalWrite(12,HIGH);
  Serial.println("touch detected");
}
else
{
   digitalWrite(12,LOW);
  Serial.println("not detected");
}
}
