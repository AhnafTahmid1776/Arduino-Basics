byte lupTable[16] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
  0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};
unsigned int k = 0;
void setup() {
  for (int i = 6; i < 15; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  byte y = lupTable[k];
  PORTB = y;
  digitalWrite(6, bitRead(y, 6));
  digitalWrite(7, bitRead(y, 7));
  delay(1000);
}
void loop() {
  if (digitalRead(15) == HIGH && digitalRead(16) == LOW) {

    digitalWrite(14, LOW);
    byte y = lupTable[k % 16];
    PORTB = y;
    digitalWrite(6, bitRead(y, 6));
    digitalWrite(7, bitRead(y, 7));
    delay(1000);
    k++;
  } else if (digitalRead(15) == LOW && digitalRead(16) == HIGH) {

    digitalWrite(14, LOW);
    byte y = lupTable[k % 16];
    PORTB = y;
    digitalWrite(6, bitRead(y, 6));
    digitalWrite(7, bitRead(y, 7));
    delay(1000);
    k--;
  }
}
