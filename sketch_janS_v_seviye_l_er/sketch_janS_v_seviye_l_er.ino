#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define lm35 A0
#define echo 9
#define triq 8
 
float doluluk;
float mesafe;
float referance =30  ;
float sure; 
float sicalik_gerilim = 0;
 int okunan_deger = 0;
 float sicalik = 0;
 int minm = 0; 
 int maxm = 50;
 float hiz ;
 void setup() {
   lcd.begin();  
   pinMode(triq,OUTPUT);
   pinMode(echo,INPUT);
   

   Serial.begin (9600);
    
}

void loop() {
  digitalWrite(triq,LOW);
  delayMicroseconds(5);
  digitalWrite(triq,HIGH);
  delayMicroseconds(10);
  digitalWrite(triq,LOW);
  
okunan_deger = analogRead(lm35);
 sicalik_gerilim = (5000.0 / 1023.0) * okunan_deger;
 sicalik = sicalik_gerilim / 10.0 ;
 Serial.println(sicalik);
 float x;
 x= sqrt(1 + ( sicalik / 273));
 hiz = 10000 / (331 * x);
 
  sure = pulseIn(echo,HIGH);
  mesafe = sure / hiz  / 2;
  doluluk = ((referance - mesafe)/referance)*100;
  if(minm <= mesafe <= maxm ){
  

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("%");
  lcd.setCursor(2,0);
  lcd.print(doluluk);
  delay(1000);
}
  if(doluluk<0){
    lcd.clear();
  }
}
