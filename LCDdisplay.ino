
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void lcdSetup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void displayLCD(float temp, float UV, uint16_t moisture, char* plant) {
  Serial.print("Species: ");
  Serial.print(plant);
  Serial.print("\t\t");
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C\t\t");
  Serial.print("UV Index: ");
  Serial.print(UV);
  Serial.print(" mW/cm^2\t\t");
  Serial.print("Soil Moisture: ");
  switch(moisture) {
    case 0:
      Serial.print("Dry");
      break;
    case 1:
      Serial.print("Perfect");
      break;
    case 2:
      Serial.print("Drowning");
      break;
  }
  Serial.print("\n");
}
