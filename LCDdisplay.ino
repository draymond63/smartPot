#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
int screen = 0;

struct plant {
  String n;       // Name
  
  float tMin;  // Temperature Range
  float tMax;
  
  uint16_t uvMin; // Hours in the sun (25 000 -> 50 000 lux) XXX (currently just strength)
  uint16_t uvMax;

  uint16_t mMin;  // % of moistness?
  uint16_t mMax;
};
//                      Name      Temp    UV    Moisture
struct plant Cactus   {"Cactus", 0, 73, 200, 500, 10, 50};
struct plant Succulent{"Succulent", 10, 35, 175, 400, 30, 70};
struct plant SunFlower{"Sun Flower", 20, 40, 200, 1000, 40, 80};
//struct plant Cactus   {"Cactus", 0, 73, 4, 15, 10, 50};
//struct plant Succulent{"Succulent", 10, 35, 6, 10, 30, 70};
//struct plant SunFlower{"Sun Flower", 20, 40, 8, 22, 40, 80};

struct plant plants[] {
  Cactus,
  Succulent,
  SunFlower,
};

// -------------------------------- SETUP
void lcdSetup() {
  lcd.begin(16, 2);
  lcd.print("Welcome!");
}

// -------------------------------- LOOP
void displayLCD(float temp, uint16_t UV, uint16_t moisture, int pType, bool changeScreen, uint8_t changePlant) {
  if (changeScreen) {
    screen++;
    screen %= 4;
  } else if (changePlant) {
    screen = 3;
  }
  
  lcd.clear();
  switch(screen) {
    case 0:
      tempS(plants[pType], temp);
      break;
    case 1:
      moistureS(plants[pType], moisture);
      break;
    case 2:
      UVS(plants[pType], UV);
      break;
    case 3:
      plantTypeS(plants[pType]);
      break;
  }
}

// -------------------------------- SCREENS
void tempS(struct plant p, float t) {
  String str = "Temp: ";
  str += String(t);
  str += " C";
  lcd.print(str);
  Serial.println(t);
  lcd.setCursor(0, 1);
  
  if (t < p.tMin)
    str = "Too cold";
  else if (t >= p.tMin && t < p.tMax)
    str = "Perfect";
  else
    str = "Too hot!";
  lcd.print(str);
}
void moistureS(struct plant p, uint16_t m) {
  lcd.print("Moisture: ");
  lcd.setCursor(0, 1);
  String str;
  Serial.println(m);
  
  if (m < p.mMin)
    str = "Needs water!";
  else if (m >= p.mMin && m < p.mMax)
    str = "Perfect";
  else
    str = "Too much!";
  
  lcd.print(str);
}
void UVS(struct plant p, uint16_t l) {
  String str = "UV: ";
  str += String(l);
  str += " uW/cm^2";
  lcd.print(str);
  Serial.print(l);

  if (l < p.uvMin)
    str = "Needs more sun!";
  else if (l >= p.uvMin && l < p.uvMax)
    str = "Perfect";
  else
    str = "Too much sun!";

  lcd.setCursor(0, 1);
  lcd.print(str);
}
void plantTypeS(struct plant p) {
  lcd.print("You have a");
  lcd.setCursor(0, 1);
  lcd.print(p.n);
}
