/*
* ESP8266 Soil Moisture Sensor
* By: SmartPot Team 
* Date: February 15th, 2020
*/

#define SensorPin A0 
uint16_t sensorValue = 0; 

uint16_t getMoisture() {
  return constrain(map(analogRead(SensorPin), 0, 1023, 100, 0), 0, 100);
}
