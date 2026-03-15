#define TRIGGER_PIN 11
#define ECHO_PIN 10
#define BUZZER_PIN 4
#define BLUE_LED 5

#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988  

unsigned long time;
unsigned long time1 = 0;
int led_state = LOW;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.begin(9600);
}

int getDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  int dist = duration * 0.034 / 2;
  return (dist == 0) ? 400 : dist;
}


void playRickRoll() {
  int melody[] = { NOTE_D5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_B5, NOTE_B5, NOTE_A5, 
                   NOTE_D5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_A5, NOTE_G5 };
  
  int durations[] = { 150, 150, 150, 150, 300, 300, 500,
                      150, 150, 150, 150, 300, 300, 500 };

  for (int i = 0; i < 14; i++) {
    tone(BUZZER_PIN, melody[i]);
    digitalWrite(BLUE_LED, HIGH); 
    delay(durations[i]);
    noTone(BUZZER_PIN);
    digitalWrite(BLUE_LED, LOW);
    delay(50); 
  }
}

void loop() {
  time = millis();
  int distance = getDistance();

  if (distance > 0 && distance < 10) {
    playRickRoll();
  } 
  else if (distance >= 10 && distance < 50) {
    if (time - time1 >= distance * 5) {
      time1 = time;
      led_state = !led_state;
      digitalWrite(BLUE_LED, led_state);
      
      if (led_state) tone(BUZZER_PIN, 800);
      else noTone(BUZZER_PIN);
    }
  } 
  else {
    noTone(BUZZER_PIN);
    digitalWrite(BLUE_LED, LOW);
  }
}