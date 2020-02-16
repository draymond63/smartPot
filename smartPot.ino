// TITLE:   Smart Pot
// PURPOSE: Let's fuck this shit
// AUTHOR:  Daniel Raymond
// DATE:    2020-20-15
// STATUS:  Broken as hell

String plant = "PLANT";

void setup() {
  Serial.begin(9600);
  
  lcdSetup();
  UVSetup();
  MSSetup();
  tempSetup();
  soundSetup();
  buttonSetup();
}

void loop() {
  float temp = getTemp();
  uint16_t moist = getMoisture(plant);
  float UV = getUV();
  displayLCD(temp, UV, moist, "PLANT", checkSound());
  checkSound();
  delay(1000);
}
