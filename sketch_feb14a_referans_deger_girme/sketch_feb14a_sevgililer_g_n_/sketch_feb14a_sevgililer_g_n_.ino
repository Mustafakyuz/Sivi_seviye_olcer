#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
#define yok 0
#define right 1
#define left 2
#define up 3
#define down 4
#define select 5

int okunan_deger = 0;
float referans_deger = 0;
int basilan_tus = 0;
int z;
int toplam;
 

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
 int toplama(int e, int u){
  z = e + u;
   return z;
  
 }
void setup() 
{
  lcd.begin(16,2);
 
      lcd.setCursor(0,0);
      lcd.print("PIKSEL OTOMASYON");
      delay(3000);
      lcd.clear();
 
  
 
}

void loop()
{
 int d = 8;
 toplam = toplama(referans_deger, d);    
      
      lcd.setCursor(6,1);
      lcd.print(referans_deger );
     
      lcd.setCursor(0,0);
      lcd.print("Ref. degeri gir:");
     
      basilan_tus = buton_bul();
   switch (basilan_tus)
   {
     case up:
     {
      referans_deger = referans_deger + 0.1;
      delay(100);
      break;
       return referans_deger;
     }
     case down:
     {
     referans_deger = referans_deger - 0.1;
     delay(100);
     break;
     return referans_deger;
     }
     
    
     
delay(100);
   }
   if ( basilan_tus = select)
   {
    lcd.print(z);
    delay(100);
   }
}

   
    
