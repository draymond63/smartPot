
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
int screen = 0;

void lcdSetup() {
  lcd.begin(16, 2);
  lcd.print("Welcome!");
}

void displayLCD(float temp, float UV, uint16_t moisture, String plant, int changeScreen) {
  if (changeScreen) {
    screen++;
    screen %= 4;
    lcd.clear();
    switch(screen) {
      case 0:
        tempS(temp);
        break;
      case 1:
        moistureS(moisture);
        break;
      case 2:
        UVS(UV);
        break;
      case 3:
        plantTypeS(plant);
        break;
    }
  }
}

void tempS(float t) {
  String str = "Temp: ";
  str += String(t);
  lcd.print(str);
}

void moistureS(uint16_t m) {
  String str = "Moisture: ";
  switch(m) {
    case 0:
        str += "Needs water!";
        break;
      case 1:
        str += "Perfect";
        break;
      case 2:
        str += "Too much!";
        break;
  }
  lcd.print(str);
}

void UVS(float l) {
  String str = "UV: ";
  
//  switch(m) {
//    case 0:
//        str += "Needs more light";
//        break;
//      case 1:
//        str += "Probably fine";
//        break;
//      case 2:
//        str += "";
//        break;
//  }
  
  str += String(l);
  str += "mW/cm^2";
  lcd.print(str);
}

void plantTypeS(String p) {
  lcd.print(p);
}
