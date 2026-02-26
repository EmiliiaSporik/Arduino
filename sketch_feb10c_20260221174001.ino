#define DATA  13
#define LATCH 12
#define CLOCK 11

#define DIGIT_1 10
#define DIGIT_2 9
#define DIGIT_3 8
#define DIGIT_4 7

byte x=0;

int digit_1;
int digit_2;
int digit_3;
int digit_4;

//                      A  B  C  D  E  F  G  H
bool indicator[10][8]={{0, 0, 0, 0, 0, 0, 1, 1}, //0
                       {1, 0, 0, 1, 1, 1, 1, 1}, //1
                       {0, 0, 1, 0, 0, 1, 0, 1}, //2
                       {0, 0, 0, 0, 1, 1, 0, 1}, //3
                       {1, 0, 0, 1, 1, 0, 0, 1}, //4
                       {0, 1, 0, 0, 1, 0, 0, 1}, //5 
                       {0, 1, 0, 0, 0, 0, 0, 1}, //6
                       {0, 0, 0, 1, 1, 1, 1, 1}, //7
                       {0, 0, 0, 0, 0, 0, 0, 1}, //8
                       {0, 0, 0, 0, 1, 0, 0, 1}};//9

void setup() {
  pinMode(DATA,  OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  pinMode(DIGIT_1, OUTPUT);
  pinMode(DIGIT_2, OUTPUT);
  pinMode(DIGIT_3, OUTPUT);
  pinMode(DIGIT_4, OUTPUT);
  
  digitalWrite(LATCH, LOW);

  digit_1=1;
  digit_2=2;
  digit_3=3;
  digit_4=4;
}

void loop() {
  
  for(int i=0; i<8; i++){
    bitWrite(x, i, indicator[digit_1][i]);
  }
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, x);
  digitalWrite(LATCH, HIGH);
  
  digitalWrite(DIGIT_1, HIGH);
  delayMicroseconds(500);
  digitalWrite(DIGIT_1, LOW);
 

  for(int i=0; i<8; i++){
    bitWrite(x, i, indicator[digit_2][i]);
  }
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, x);
  digitalWrite(LATCH, HIGH);
  
  digitalWrite(DIGIT_2, HIGH);
  delayMicroseconds(500);
  digitalWrite(DIGIT_2, LOW);


  for(int i=0; i<8; i++){
    bitWrite(x, i, indicator[digit_3][i]);
  }
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, x);
  digitalWrite(LATCH, HIGH);
  
  digitalWrite(DIGIT_3, HIGH);
  delayMicroseconds(500);
  digitalWrite(DIGIT_3, LOW);;


  for(int i=0; i<10; i++){
    bitWrite(x, i, indicator[digit_4][i]);
  }
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, x);
  digitalWrite(LATCH, HIGH);
 
  digitalWrite(DIGIT_4, HIGH);
  delayMicroseconds(500);
  digitalWrite(DIGIT_4, LOW);

}
