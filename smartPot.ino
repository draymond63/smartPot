// TITLE:   Smart Pot
// PURPOSE: Let's fuck this shit
// AUTHOR:  Daniel Raymond
// DATE:    2020-20-15
// STATUS:  Broken as hell

#define CACTUS    0
#define SUCCULENT 1
#define SUNFLOWER 2

uint8_t pI = SUCCULENT;
uint8_t bP = false;

void setup() {
  Serial.begin(9600);
  lcdSetup();
  UVSetup();
  btnIntSetup();
  soundSetup();
}

void loop() {
  if (checkBtn()) {
    pI++;
    pI %= 3;
    bP = true;
    delay(5);
  } else
    bP = false;
  
  displayLCD(getTemp(), getUV(), getMoisture(), pI, checkSound(), bP );
  delay(1000);
}
