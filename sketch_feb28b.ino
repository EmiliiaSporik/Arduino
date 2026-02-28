const int dataPin = 11; 
const int clockPin = 13;
const int latchPin = 10;

int numbers[] = {
  0b11111100, // 0
  0b01100000, // 1
  0b11011010, // 2
  0b11110010, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100000, // 7
  0b11111110, // 8
  0b11110110  // 9
};

void setup() {
  Serial.begin(9600); 
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
}

void loop() {
  if (Serial.available() > 0) {
    int a = Serial.parseInt();
    
    int b = Serial.parseInt();

    int c = a + b;
    
    if (c >= 0 && c <= 9) {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, numbers[c]);
      digitalWrite(latchPin, HIGH);
    }
  }
}