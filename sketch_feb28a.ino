#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 12;    
int counter = 0;       
bool lastButtonState = HIGH; 

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(buttonPin, INPUT_PULLUP);
  
  lcd.setCursor(0, 0);
  lcd.print("Number:");
  
  updateDisplay();
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    delay(50); 
    if (digitalRead(buttonPin) == LOW) {
      counter++;     
      updateDisplay(); 
    }
  }


  lastButtonState = currentButtonState;
}

void updateDisplay() {
  lcd.setCursor(0, 1);
  lcd.print(counter);
  lcd.print("   "); 
}