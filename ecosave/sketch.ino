#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensor = 9;    // Pino PIR
const int led = 13;      // Pino LED
const unsigned long delayTime = 15000; // 15s

int state = LOW;
unsigned long lastMotionTime = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("TechnicalUpdate");
  delay(2000);
  lcd.clear();
}

void loop() {
  handleMotionDetection();
}

void handleMotionDetection() {
  int val = digitalRead(sensor);

  if (val == HIGH) {
    if (state == LOW) {
      updateDisplay("Motion Detected!");
      digitalWrite(led, HIGH);
      lastMotionTime = millis();
      state = HIGH;
    }
  } else if (state == HIGH && (millis() - lastMotionTime > delayTime)) {
    updateDisplay("No Motion");
    digitalWrite(led, LOW);
    state = LOW;
  }
}

void updateDisplay(String message) {
  lcd.clear();
  lcd.print(message);
}
