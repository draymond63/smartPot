
int soundDetectedPin = 3; // Use Pin 10 as our Input
int soundDetectedVal = LOW; // This is where we record our Sound Measurement

void soundSetup ()
{
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
  attachInterrupt(digitalPinToInterrupt(soundDetectedPin), whenSound, RISING);
}

void whenSound () {
  soundDetectedVal = true;
}

void checkSound() {
  if (soundDetectedVal==HIGH) {
    Serial.println("hell yeah");
    delay (1000);
    soundDetectedVal= false;
  }
  else {
    Serial.println("nope");
  }
}
