// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void lcdSetup() {
  
}

void displayLCD(uint16_t temp, uint16_t UV, uint16_t moisture, char* plant) {
  PORTB ^= 1 << PB5;
}
