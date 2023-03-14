include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);
float pg=0;
int b=3;

int sensor =2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(b,OUTPUT);
pinMode(sensor,INPUT);


lcd.init();
lcd.backlight();


}

void loop() {

  pg=analogRead(A0);
  if(digitalRead(sensor)==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("sin presencia de");
    lcd.setCursor(6,1);
    lcd.print("alc");
    Serial.println("sin presencia de alc");
    digitalWrite(b,0);
    
  }
  

  else{

 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("p de alcohol ");
 lcd.setCursor(4,1);
 
 lcd.print(float(pg/100));
 lcd.setCursor(10,1);
 lcd.print("%A");
 
 Serial.println("p de alcohol ");
  Serial.println(pg);
 digitalWrite(b,1);
 
    
  }
  // put your main code here, to run repeatedly:
delay(1000);
}