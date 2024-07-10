
#include <Encoder.h>

//this code uses the Encoder Library.
Encoder nemaPos(2, 3);
long oldPosition = -999;
unsigned long currentPos;
unsigned long timeNow;
int bPin1 = 4;
int bPin2 = 5;
int bPin3 = 6;
int bPin4 = 7;
int bPin5 = 8;
int bPin6 = 9;
int bPin7 = 10;
int bPin8 = 11;
int bPin9 = 12;
int bPin10 = 13;
int bPin11 = 14;
int bPin12 = 15;
int bPin13 = 16;
int bPin14 = 17;
int bPin15 = 18;
int bPin16 = 19;


void setup() {
  // put your setup code here, to run once:
  nemaPos.write(4000);

  pinMode(bPin1, OUTPUT);
  pinMode(bPin2, OUTPUT);
  pinMode(bPin3, OUTPUT);
  pinMode(bPin4, OUTPUT);
  pinMode(bPin5, OUTPUT);
  pinMode(bPin6, OUTPUT);
  pinMode(bPin7, OUTPUT);
  pinMode(bPin8, OUTPUT);
  pinMode(bPin9, OUTPUT);
  pinMode(bPin10, OUTPUT);
  pinMode(bPin11, OUTPUT);
  pinMode(bPin12, OUTPUT);
  pinMode(bPin13, OUTPUT);
  pinMode(bPin14, OUTPUT);
  pinMode(bPin15, OUTPUT);
  pinMode(bPin16, OUTPUT);

  digitalWrite(bPin1, LOW);
  digitalWrite(bPin2, LOW);
  digitalWrite(bPin3, LOW);
  digitalWrite(bPin4, LOW);
  digitalWrite(bPin5, LOW);
  digitalWrite(bPin6, LOW);
  digitalWrite(bPin7, LOW);
  digitalWrite(bPin8, LOW);
  digitalWrite(bPin9, LOW);
  digitalWrite(bPin10, LOW);
  digitalWrite(bPin11, LOW);
  digitalWrite(bPin12, LOW);
  digitalWrite(bPin13, LOW);
  digitalWrite(bPin14, LOW);
  digitalWrite(bPin15, LOW);
  digitalWrite(bPin16, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (nemaPos.read() <= 0 ){
    nemaPos.write(4000);
  }
  currentPos = nemaPos.read();
  timeNow = millis();
  //nemaPos.read() should return the incremental count, positive or negitive.
  // this encoder library counts for every signal change.  
  //so for a 1000PPR encoder it should count 4000 counts per rev(low certainty)

  if (currentPos != oldPosition){
    oldPosition = currentPos;

    digitalWrite(bPin1, currentPos & 0b1);
    digitalWrite(bPin2, currentPos & 0b10);
    digitalWrite(bPin3, currentPos & 0b100);
    digitalWrite(bPin4, currentPos & 0b1000);
    digitalWrite(bPin5, currentPos & 0b10000);
    digitalWrite(bPin6, currentPos & 0b100000);
    digitalWrite(bPin7, currentPos & 0b1000000);
    digitalWrite(bPin8, currentPos & 0b10000000);
    digitalWrite(bPin9, currentPos & 0b100000000);
    digitalWrite(bPin10, currentPos & 0b1000000000);
    digitalWrite(bPin11, currentPos & 0b10000000000);
    digitalWrite(bPin12, currentPos & 0b100000000000);
    digitalWrite(bPin13, currentPos & 0b1000000000000);
    digitalWrite(bPin14, currentPos & 0b10000000000000);
    digitalWrite(bPin15, currentPos & 0b100000000000000);
    digitalWrite(bPin16, currentPos & 0b1000000000000000);
  }
  if (currentPos <= 0 || currentPos >= 8000){
    nemaPos.write(4000);
  }
  delay(5);
}

