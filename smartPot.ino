// TITLE:   Smart Pot
// PURPOSE: Let's fuck this shit
// AUTHOR:  Daniel Raymond
// DATE:    2020-20-15
// STATUS:  Broken as hell

void setup() {
  Serial.begin(9600);
  DDRB = 1 << PB5;
}

void loop() {
  uint16_t temp = getTemp();
  uint16_t moist = getMoisture();
  uint16_t UV = getUV();
  displayLCD(temp, UV, moist, "PLANT");
  delay(1000);
}
