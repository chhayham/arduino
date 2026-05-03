#include <Keyboard.h>

// Joystick Pins
const int PIN_X = A0;
const int PIN_Y = A1;
const int PIN_B = 14; // sel pin

// Thresholds for directional movement
const int threshold = 300; 
const int center = 512;

void setup() {
  pinMode(PIN_B, INPUT);
  Keyboard.begin();
}

void loop() {
  int xValue = analogRead(PIN_X);
  int yValue = analogRead(PIN_Y);
  int bValue = digitalRead(PIN_B);

  // Up/Down (Y-axis)
  if (yValue < center - threshold) {
    Keyboard.press('KEY_UP_ARROW'); // Up
  } else if (yValue > center + threshold) {
    Keyboard.press('KEY_DOWN_ARROW'); // Down
  } else {
    Keyboard.release('KEY_UP_ARROW');
    Keyboard.release('KEY_DOWN_ARROW');
  }

  // Left/Right (X-axis)
  if (xValue < center - threshold) {
    Keyboard.press('KEY_LEFT_ARROW'); // Left
  } else if (xValue > center + threshold) {
    Keyboard.press('KEY_RIGHT_ARROW'); // Right
  } else {
    Keyboard.release('KEY_LEFT_ARROW');
    Keyboard.release('KEY_RIGHT_ARROW');
  }

  // Button
  if (bValue == HIGH) {
    Keyboard.press('`'); // ` keybind
  } else {
    Keyboard.release('`');
  }
  
  delay(50); // Small delay for stability
}
