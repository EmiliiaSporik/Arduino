int green_led = 4;
int blue_led = 5;
int blue1_led = 6;
int blue2_led = 7;
int white_led = 8;

void setup() {
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(blue1_led, OUTPUT);
  pinMode(blue2_led, OUTPUT);
  pinMode(white_led, OUTPUT);
}

void loop() {
  int value = analogRead(A0);
  
  digitalWrite(green_led, HIGH);
  delay(value * 5);
  digitalWrite(green_led, LOW);

  digitalWrite(blue_led, HIGH);
  delay(value * 5);
  digitalWrite(blue_led, LOW);

  digitalWrite(blue1_led, HIGH);
  delay(value * 5);
  digitalWrite(blue1_led, LOW);

  digitalWrite(blue2_led, HIGH);
  delay(value * 5);
  digitalWrite(blue2_led, LOW);

  digitalWrite(white_led, HIGH);
  delay(value * 5);
  digitalWrite(white_led, LOW);
}