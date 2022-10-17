#define arttir 4
#define azalt 5
#define hesapla 6
#define lm35 A0
#define echo 9
#define triq 8                                                 // pin tanımlamaları
#include <Wire.h>
#include <LiquidCrystal_I2C.h>                                 // kütüphaneler
LiquidCrystal_I2C lcd(0x27, 16, 2); 
int referans_deger = 0;
int durum_arttir;
int durum_azalt;
int durum_hesapla;
float doluluk;
float mesafe;
float sure; 
float sicalik_gerilim = 0;
int okunan_deger = 0;
float sicalik = 0;
int minm = 0; 
int maxm = 50;
float hiz ;                                                     // değerler
void doluluk_orani(){                                          
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
  doluluk = ((referans_deger - mesafe)/referans_deger)*100;
  return doluluk;
}                                                               // girilen referans değere göre dolum oranını hesaplayan fonksiyon
void setup() {
   pinMode(triq,OUTPUT);
   pinMode(echo,INPUT);
   pinMode(arttir , INPUT);
   pinMode(azalt , INPUT);
   pinMode(hesapla , INPUT);                                    // Veri girişi
  Serial.begin(9600);
   lcd.begin();
   lcd.setCursor(0,0);
   lcd.print("PIKSEL OTOMASYON");
   delay(3000);
   lcd.clear();
}

void loop() {  
    durum_hesapla = digitalRead(hesapla);
    while(durum_hesapla == LOW){                                 // 
    lcd.setCursor(0,0);
    lcd.print("Referans gir:");
    lcd.setCursor(13 , 0);
    lcd.print(referans_deger);
       durum_arttir = digitalRead(arttir);
       durum_azalt = digitalRead(azalt);
         if(durum_arttir == HIGH){
         referans_deger++;
         lcd.setCursor(0,0);
         lcd.print("Referans gir:");
         lcd.setCursor(13 , 0);
         lcd.print(referans_deger);
         return referans_deger;
         }
         else if(durum_azalt == HIGH){
         referans_deger--;
         lcd.setCursor(0,0);
         lcd.print("Referans gir:");
         lcd.setCursor(13 , 0);
         lcd.print(referans_deger);
         return referans_deger;
         }
    durum_hesapla = digitalRead(hesapla);
    lcd.clear();
    }                                                               // Referans değer girişi
   while(durum_hesapla == HIGH){
   doluluk_orani();
       lcd.clear();
    
       lcd.setCursor(0,0);
       lcd.print("Doluluk orani:   ");
       lcd.setCursor(7,1);
       lcd.print("%");
       lcd.setCursor(8,1);
       lcd.print(doluluk); 
       durum_hesapla = digitalRead(hesapla);   
   }                                                                // Doluluk oranını LCD ye yazdırma
  
}
