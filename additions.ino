byte luptable[16]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,       //cc-codes for: 0-9
                    0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71       //cc-code for: A-F
};
byte x1 = 0x32;
byte x2 = 0x27;
byte sum =x1 + x2; // sum = 65

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i=6; i<=15; i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
// put your main code here, to run repeatedly:
digitalWrite(A0,LOW);
byte y=luptable[sum/16];

PORTB =y;
digitalWrite(6,bitRead(y,6));
digitalWrite(7,bitRead(y,7));
delay(1000);

digitalWrite(A0,LOW);
byte x =luptable[sum% 16]  ;
PORTB =x;
digitalWrite(6,bitRead(x,6));
digitalWrite(7,bitRead(x,7));

delay(1000);

}
