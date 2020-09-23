#include <Servo.h>

Servo servo;
int light1,light2,a=10,error=65,ip=90;

void setup() {
  pinMode(a,OUTPUT);
   pinMode(A1, INPUT);   
  pinMode(A0, INPUT);
     servo.attach(12);
Serial.begin(9600);
servo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
light1=analogRead(A1);
light2=analogRead(A0);
Serial.println(light1);
Serial.println(light2);


int diff1=abs(light1-light2);
int diff2=abs(light2-light1);
if((diff1 <= error) || (diff2 <= error)) {
  ip=ip+0;
  } else {    
    if(light1 > light2)
    {
      ip=ip-1;;  
    }
    if(light1 < light2) 
    {
      ip=ip+1; 
    }
  }
 servo.write(ip); 
  delay(100);
 }
