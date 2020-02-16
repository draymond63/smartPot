 /* 
 ML8511 UV Sensor
 By: SmartPot team
 Date: February 15th, 2020
 License: Beerware 
 Note: If we do ever meet Nathan Seidle, we must buy him a beer
*/

//Hardware pin definitions
int UVOUT = A2; //Output from the sensor

void UVSetup() {
  Serial.begin(9600);
  pinMode(UVOUT, INPUT);
}

float getUV() {
  int uvLevel = averageAnalogRead(UVOUT);

  //Use the 3.3V power pin as a reference to get a very accurate output value from sensor
  float outputVoltage = 0.005 * uvLevel;

  uint16_t uvIntensity = round(mapfloat(outputVoltage, 0.99, 2.8, 0.0, 15.0) * 1000); //Convert the voltage to a UV intensity level

//  Serial.println(uvIntensity);  
  return uvIntensity;
}

//Takes an average of readings on a given pin
//Returns the average
int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0; 

  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;

  return(runningValue);  
}

//The Arduino Map function but for floats
//From: http://forum.arduino.cc/index.php?topic=3922.0
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
