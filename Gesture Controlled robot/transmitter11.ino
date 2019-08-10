#include<SoftwareSerial.h>
SoftwareSerial BTserial(A3, A4);

int x_pin = A0;
int y_pin = A1;
//int state = 0;
int x_val = 0;
int x_threshold= 350;
int y_threshold= 330;
int y_val=0;
void setup() {
  Serial.begin(9600);
  BTserial.begin(38400);
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  delay(5000);
}
void loop(){
   x_val = analogRead(x_pin);
   y_val = analogRead(y_pin);
   Serial.println(x_val);
   Serial.println(y_val );
     if (x_val > 400 )
     BTserial.write('1');
     
     else if (x_val < 310 )
     BTserial.write('2');

     else if(y_val > 360)
     BTserial.write('3');

     else if(y_val < 310)
     BTserial.write('4');
   
     else 
     BTserial.write('0');
     
    delay(10);
}
