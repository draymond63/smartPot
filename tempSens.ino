
/* For Thermistor
 *  B: 3950 +- 1%
 *  T0: 25 C
 *  Range: -55 C to 125 C
 */

//Parameters for Voltage and Resistance values
float VCC = 5.0;       //Voltage in [V]
float RAdd = 10000;    //Resistor added [ohm]
float RT0 = 10000;     //Resistor Value at T0 [ohm]
float T0 = 298.15;     //T0 in Kelvin [K]
float Bval = 3950;

float VThermo, VRes;          //Voltage Read at Thermo & at Resistor
float RThermo;                //Resistance Caused
float TempC, TempF, TempK;    //Temp in Celsius, Farenheit, Kelvin
float ln;                    

void tempSetup()
{
  Serial.begin(9600);  
}
float getTemp(void) {
  VThermo = analogRead(A1); //change analog pin accordingly
  VThermo = (VCC/1023.00) * VThermo; //convert to Voltage
  VRes = VCC - VThermo;
  RThermo = VThermo / (VRes / RAdd);

  ln = log(RThermo / RT0);
  TempK = (1 / ((ln/Bval) + (1/T0)));

  TempC = TempK - 273.15;
  TempF = (TempC * (9/5)) + 32;

  Serial.print("Temperature: ");
  Serial.print(TempC);
  Serial.print(" C and ");
  
  Serial.print(TempF);
  Serial.println(" F");
  delay(500);
  return TempC;
}
