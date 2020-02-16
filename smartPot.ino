// TITLE:   Smart Pot
// PURPOSE: Let's fuck this shit
// AUTHOR:  Daniel Raymond
// DATE:    2020-20-15
// STATUS:  Broken as hell

#define CACTUS    0
#define SUCCULENT 1
#define SUNFLOWER 2

float temp;
uint16_t moist;
uint16_t UV;
uint8_t pI = SUCCULENT;

void setup() {
  Serial.begin(9600);
  lcdSetup();
  UVSetup();
  soundSetup();
}

void loop() {
  temp = getTemp();
  moist = getMoisture();
  UV = getUV();
  displayLCD(temp, UV, moist, pI, checkSound() );
  delay(1000);
}
