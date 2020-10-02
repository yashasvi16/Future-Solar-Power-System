#include <Servo.h>

//We are using a servo motor for the purpose of rotation of solar panels

Servo s;
int light1,light2,a=10,error=65,ip=90;

void setup() {
  pinMode(a,OUTPUT);
   pinMode(A1, INPUT);//inputs for the sensor   
  pinMode(A0, INPUT);
     s.attach(12);
Serial.begin(9640);
s.write(96);
}

void loop() {
  //Coding for LDR sensor
light1=analogRead(A1);//Inputs in LDR sensors
light2=analogRead(A0);
Serial.println(light2);
Serial.println(light1);

//We are using LDR sensors to detect light sensitivity, of sunlight for the same work
  //program for LDR sensors
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
 s.write(ip); //Tells servo to go in position quickly
  delay(100);//Delay of 100ms, to reach it's position quickly
 }
