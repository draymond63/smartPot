/*
* ESP8266 Soil Moisture Sensor
* By: SmartPot Team 
* Date: February 15th, 2020
*/

#define SensorPin A0 
uint16_t sensorValue = 0; 

void MSSetup() {

}

uint16_t getMoisture(void) {
  sensorValue = constrain(map(analogRead(SensorPin), 0, 1023, 0, 100), 0, 100);
//  Serial.println(sensorValue); 
  if (sensorValue > 80) {
    return 0;
  }
  else if (sensorValue > 40) {
    return 1;
  }
  else {
    return 2;
  }
}
