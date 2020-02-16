
uint8_t btnPress = 0;

void btnIntSetup() {
    attachInterrupt(digitalPinToInterrupt(2), changePlant, RISING);
}

void changePlant() {
  btnPress = 1;
}

uint8_t checkBtn() {
  if (btnPress) {
    btnPress = 0;
    return true;
  } else
    return false;
}
