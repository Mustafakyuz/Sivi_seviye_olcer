#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
String menuItems[] = {"ITEM 1", "ITEM 2", "ITEM 3", "ITEM 4", "ITEM 5", "ITEM 6"};
void menuItem1() { // Function executes when you select the 1st item from main menu
  int activeButton = 0;
  lcd.clear();
  lcd.setCursor(0, 1);
  drawInstructions();
  lcd.setCursor(0, 0);
  lcd.print("DISTANCE: ");
  lcd.print(savedDistance);
  lcd.print(" in");
  while (activeButton == 0) {
    int button;
    readKey = analogRead(0);
    if (readKey < 790) {
      delay(100);
      readKey = analogRead(0);
    }
    button = evaluateButton(readKey);
    switch (button) {
      case 2:
        button = 0;
        savedDistance = savedDistance + 1;
        savedDistance = constrain(savedDistance,0,36);
        lcd.setCursor(10,0);
        lcd.print("     ");
        lcd.setCursor(10,0);        
        lcd.print(savedDistance);
        lcd.print(" in");
        break;
      case 3:
        button = 0;
        savedDistance = savedDistance - 1;
        savedDistance = constrain(savedDistance,0,36);
        lcd.setCursor(10,0);
        lcd.print("     ");
        lcd.setCursor(10,0);
        lcd.print(savedDistance);
        lcd.print(" in");
        break;
      case 4:  // This case will execute if the "back" button is pressed
        button = 0;
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("-- VALUES --");
        lcd.setCursor(2,1);
        lcd.print("-- STORED --");
        delay(1500);
        activeButton = 1;
        break;
    }
  }
}
