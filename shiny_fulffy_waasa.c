#include <Servo.h>
const byte pulsA =2;
const byte pulsb =3;
const byte servopin =9;
Servo servo ;
byte pulsAstate=HIGH;
byte pulsbstate=LOW;
byte servopos=89;

void setup() {
  // put your setup code here, to run once:
pinMode(pulsA,INPUT_PULLUP);
pinMode(pulsb,INPUT_PULLUP);
servo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
readpuls();
moveservo();
}
void readpuls(){
  pulsAstate=digitalRead(pulsA);
  pulsbstate=digitalRead(pulsb);
}
void moveservo(){
  if (pulsAstate==LOW){
    servopos=179;
  }
   if (pulsbstate==LOW){
    servopos=0;
  }
  servo.write(servopos);
  delay(100);
}
