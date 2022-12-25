byte lupTable[16] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
  0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};
int t = 0;
void setup() {
  for (int i = 6; i < 16; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(16, INPUT);
}

void loop() {

  if (digitalRead(16 )== HIGH) {
    for (int l = 0; l < 50; l++) {
      byte sd1 = lupTable[(t % 60) / 10];
      PORTB = sd1;
      digitalWrite(6, bitRead(sd1, 6));
      digitalWrite(7, bitRead(sd1, 7));
      digitalWrite(A0, LOW);
      digitalWrite(A1, HIGH);
      delay(10);
      byte sd2 = lupTable[(t % 60) % 10];
      PORTB = sd2;
      digitalWrite(6, bitRead(sd2, 6));
      digitalWrite(7, bitRead(sd2, 7));
      digitalWrite(A0, HIGH);
      digitalWrite(A1, LOW);
      delay(10);
    }
    t++;
  }

  else if(digitalRead(16 )== LOW) {
    byte sd1 = lupTable[(t % 60) / 10];
    PORTB = sd1;
    digitalWrite(6, bitRead(sd1, 6));
    digitalWrite(7, bitRead(sd1, 7));
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    delay(10);
    byte sd2 = lupTable[(t % 60) % 10];
    PORTB = sd2;
    digitalWrite(6, bitRead(sd2, 6));
    digitalWrite(7, bitRead(sd2, 7));
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    delay(10);
  }
}
