// TITLE:   Smart Pot
// PURPOSE: Let's fuck this shit
// AUTHOR:  Daniel Raymond
// DATE:    2020-20-15
// STATUS:  Broken as hell

#define CACTUS    0
#define SUCCULENT 1
#define SUNFLOWER 2

#define SCREENCHANGERATE 6

uint8_t pI = SUCCULENT;   // Plant Index
uint8_t bP = false;       // Button Pressed (for plant change)
uint8_t incr = 0;         // Screen change counter

void setup() {
  Serial.begin(9600);
  lcdSetup();
  UVSetup();
  btnIntSetup();
}

void loop() {
  if (checkBtn()) {
    pI++;
    pI %= 3;
    bP = true;
    incr = 0;
    delay(5);
  } else
    bP = false;
  
  displayLCD(getTemp(), getUV(), getMoisture(), pI, changeScreen(), bP );
  delay(1000);
  incr++;
}

bool changeScreen() {
  if (incr == SCREENCHANGERATE) {
    incr = 0;
    return true;
  } else
    return false;
}
