
/* For Thermistor
 *  B: 3950 +- 1%
 *  T0: 25 C
 *  Range: -55 C to 125 C
 */

//Parameters for Voltage and Resistance values
#define VCC 5
#define RAdd 10000    //Resistor added [ohm]
#define RT0 10000     //Resistor Value at T0 [ohm]
#define T0 298.15     //T0 in Kelvin [K]
#define Bval 3950

float VThermo, VRes;          //Voltage Read at Thermo & at Resistor
float RThermo;                //Resistance Caused
float TempC, TempF, TempK;    //Temp in Celsius, Farenheit, Kelvin
float ln;    

void tempSetup() {
  
}

float getTemp() {
  VThermo = analogRead(A1); //change analog pin accordingly
  VThermo = (VCC/1023.00) * VThermo; //convert to Voltage
  VRes = VCC - VThermo;
  RThermo = VThermo / (VRes / RAdd);

  ln = log(RThermo / RT0);
  TempK = (1 / ((ln/Bval) + (1/T0)));

  TempC = TempK - 273.15;
  TempF = (TempC * (9/5)) + 32;

  return TempC;
}
