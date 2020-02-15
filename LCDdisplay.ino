
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void lcdSetup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void displayLCD(float temp, uint16_t UV, uint16_t moisture, char* plant) {
  
}
