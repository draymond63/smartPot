
int soundDetectedPin = 3; // Use Pin 10 as our Input
int soundDetectedVal = LOW; // This is where we record our Sound Measurement

void soundSetup () {
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
  attachInterrupt(digitalPinToInterrupt(soundDetectedPin), whenSound, RISING);
}

void whenSound () {
  soundDetectedVal = true;
}

int checkSound() {
  if (soundDetectedVal) {
    soundDetectedVal = false;
    return true;
  }
  else
    return false;
}
