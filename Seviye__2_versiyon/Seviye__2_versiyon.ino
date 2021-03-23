#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
#define yok 0
#define right 1
#define left 2
#define up 3
#define down 4
#define select 5
#define lm35 A1
#define echo 11
#define triq 12
int okunan_deger =0;
float referans_deger = 0;
int basilan_tus =0;
float doluluk;
float mesafe;
float sure; 
float sicalik_gerilim = 0;
 int okunan_degerlm35 = 0;
 float sicalik = 0;
 int minm = 0; 
 int maxm = 50;
 float hiz ;
byte buton_bul()
 {
okunan_deger = analogRead(A0);
   if(okunan_deger>1000)
   return yok;
  if(okunan_deger<50)
   return right;
  if(okunan_deger<200)
   return up;
  if(okunan_deger<350)
   return down; 
  if(okunan_deger<500)
   return left;
  if(okunan_deger<750)
   return select;
 }
   
void setup() {
   lcd.begin(16,2);

}

void loop() {
 digitalWrite(triq,LOW);
  delayMicroseconds(5);
  digitalWrite(triq,HIGH);
  delayMicroseconds(10);
  digitalWrite(triq,LOW);  

   lcd.setCursor(12,0);
   lcd.print(referans_deger );
   lcd.setCursor(0,0);
   lcd.print("Ref. gir:");
   
  lcd.setCursor(1,1);
  lcd.print("%");
  lcd.setCursor(2,1);
  lcd.print(doluluk);
   
     
      
      basilan_tus = buton_bul();
   switch (basilan_tus)
   {
     case up:
     {
      referans_deger = referans_deger + 1;
    lcd.setCursor(6,1);
      lcd.print(referans_deger );
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Ref. degeri gir:");
      delay(100);
      break;
     }
     case down:
     {
     referans_deger = referans_deger - 1;
     lcd.setCursor(6,1);
      lcd.print(referans_deger );
      lcd.clear();
       lcd.setCursor(0,0);
      lcd.print("Ref. degeri gir:");
      delay(100);
     break;
     }    
     delay(100);
   }
   if( basilan_tus = select){
    okunan_degerlm35 = analogRead(lm35);
       sicalik_gerilim = (5000.0 / 1023.0) * okunan_deger;
       sicalik = sicalik_gerilim / 10.0 ;
       Serial.println(sicalik);
      float x;
      x= sqrt(1 + ( sicalik / 273));
      hiz = 10000 / (331 * x);
 
     sure = pulseIn(echo,HIGH);
     mesafe = sure / hiz  / 2;
     doluluk = ((referans_deger - mesafe)/referans_deger)*100;
    
   }
}
