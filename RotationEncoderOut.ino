
#include <Encoder.h>

//this code uses the Encoder Library.
Encoder nemaPos(2, 3);
long oldPosition = -999;
unsigned long currentPos;
unsigned long timeNow;
bool bit1;
bool bit2;
bool bit3;
bool bit4;
bool bit5;
bool bit6;
bool bit7;
bool bit8;
bool bit9;
bool bit10;
bool bit11;
bool bit12;
bool bit13;
bool bit14;
bool bit15;
bool bit16;
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
  Serial.begin(9600);
  Serial.println("code start.");
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
    Serial.println(currentPos);
    Serial.println(timeNow);

    
     bit1 = currentPos & 0b1;
     bit2 = currentPos & 0b10;
     bit3 = currentPos & 0b100;
     bit4 = currentPos & 0b1000;
     bit5 = currentPos & 0b10000;
     bit6 = currentPos & 0b100000;
     bit7 = currentPos & 0b1000000;
     bit8 = currentPos & 0b10000000;
     bit9 = currentPos & 0b100000000;
     bit10 = currentPos & 0b1000000000;
     bit11 = currentPos & 0b10000000000;
     bit12 = currentPos & 0b100000000000;
     bit13 = currentPos & 0b1000000000000;
     bit14 = currentPos & 0b10000000000000;
     bit15 = currentPos & 0b100000000000000;
     bit16 = currentPos & 0b100000000000000;
    //Serial.println(bit1+bit2+bit3+bit4+bit5+bit6+bit7+bit8+bit9+bit10+bit11+bit12+bit13+bit14+bit15+bit16);
   // Serial.println(bit1+bit2+bit3+bit4+bit5+bit6+bit7+bit8);
    

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

    
    Serial.println(" ");

    Serial.print(bit16);
    Serial.print(bit15);
    Serial.print(bit14);
    Serial.print(bit13);
    Serial.print(bit12);
    Serial.print(bit11);
    Serial.print(bit10);
    Serial.print(bit9);
    Serial.print(bit8);
    Serial.print(bit7);
    Serial.print(bit6);
    Serial.print(bit5);
    Serial.print(bit4);
    Serial.print(bit3);
    Serial.print(bit2);
    Serial.print(bit1);

    Serial.println(" ");
    

  }
  if (currentPos <= 0 || currentPos >= 8000){
    nemaPos.write(4000);
  }
  delay(9);


}

