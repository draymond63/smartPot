// TITLE:   Smart Pot
// PURPOSE: Let's fuck this shit
// AUTHOR:  Daniel Raymond
// DATE:    2020-20-15
// STATUS:  Broken as hell

float temp;
uint16_t moist;
float UV;
String plant = "PLANT";

void setup() {
  Serial.begin(9600);
  lcdSetup();
  UVSetup();
  MSSetup();
  tempSetup();
  soundSetup();
}

void loop() {
  temp = getTemp();
  moist = getMoisture(plant);
  UV = getUV();
  displayLCD(temp, UV, moist, plant, checkSound());
  delay(1000);
}
