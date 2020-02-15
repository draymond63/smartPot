// TITLE:   Smart Pot
// PURPOSE: Let's fuck this shit
// AUTHOR:  Daniel Raymond
// DATE:    2020-20-15
// STATUS:  Broken as hell

void setup() {
  Serial.begin(9600);
  
  lcdSetup();
  UVSetup();
  MSSetup();
  tempSetup();
}

void loop() {
  float temp = getTemp();
  uint16_t moist = getMoisture();
  float UV = getUV();
  displayLCD(temp, UV, moist, "PLANT");
  delay(1000);
}
