 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27, 16, 2); 
 void setup() {
 lcd.begin();
 

}

void loop() {
  lcd.setCursor(1,10);
  lcd.print("SEVGILILER GUNUMUZ");
  for (int a=1 ; a<100; a++)
  lcd.scrollDisplayLeft();
  delay(300);
  
  
}
// lcd.clear(); => ekran temizleme
// lcd.setCursor(satır,sütun); => yazıynın konum
// lcd.scrollDisplayLeft(); => kaydırma
// lcd.home(); => yazı yazılacak yeri sol üste sabitler
