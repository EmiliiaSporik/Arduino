int green_led = 4;
int blue_led = 5;
int blue1_led = 6;
int blue2_led = 7;
int white_led = 8;

void setup() {
  Serial.begin(9600);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(blue1_led, OUTPUT);
  pinMode(blue2_led, OUTPUT);
  pinMode(white_led, OUTPUT);
}

void loop() {
  int value = analogRead(A0); 
  if (value == 0) {
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
    digitalWrite(blue1_led, LOW);
    digitalWrite(blue2_led, LOW);
    digitalWrite(white_led, LOW);
  }

  if (value > 0 && value < 204.6) {
    digitalWrite(green_led, HIGH);
    digitalWrite(blue_led, LOW);
    digitalWrite(blue1_led, LOW);
    digitalWrite(blue2_led, LOW);
    digitalWrite(white_led, LOW);
  } 
  
  else if (value >= 204.6 && value < 409.2) {
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, HIGH);
    digitalWrite(blue1_led, LOW);
    digitalWrite(blue2_led, LOW);
    digitalWrite(white_led, LOW);
  } 

  else if (value >= 409.2 && value < 613.8) {
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
    digitalWrite(blue1_led, HIGH);
    digitalWrite(blue2_led, LOW);
    digitalWrite(white_led, LOW);
  } 

  else if (value >= 613.8 && value < 818.4) {
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
    digitalWrite(blue1_led, LOW);
    digitalWrite(blue2_led, HIGH);
    digitalWrite(white_led, LOW);
  } 

  else if (value >= 818.4 && value <= 1023) {
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
    digitalWrite(blue1_led, LOW);
    digitalWrite(blue2_led, LOW);
    digitalWrite(white_led, HIGH);
  }
}