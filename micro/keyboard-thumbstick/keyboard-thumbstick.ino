#include <Keyboard.h>

// Joystick Pins
const int PIN_X = A0;
const int PIN_Y = A1;
const int PIN_B = 14; // sel pin

// Thresholds for directional movement
const int threshold = 175;
const int center = 512;


void setup() {
  pinMode(PIN_B, INPUT_PULLUP);
  Serial.begin(115200);
  Keyboard.begin();
}

void loop() {
  int xValue = analogRead(PIN_X);
  int yValue = analogRead(PIN_Y);
  int bValue = digitalRead(PIN_B);
  bool isPressed = (bValue == LOW);

  // Up/Down (Y-axis)
  if (yValue < center - threshold) {
    Serial.print("up value: ");
    Serial.println(yValue);
    Keyboard.press(KEY_UP_ARROW); // Up key
  } else if (yValue > center + threshold) {
    Serial.print("down value: ");
    Serial.println(yValue);
    Keyboard.press(KEY_DOWN_ARROW); // Down key
  } else {
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
  }

  // Left/Right (X-axis)
  if (xValue < center - threshold) {
    Serial.print("left value: ");
    Serial.println(xValue);
    Keyboard.press(KEY_LEFT_ARROW); // Left key
  } else if (xValue > center + threshold) {
    Serial.print("right value: ");
    Serial.println(xValue);
    Keyboard.press(KEY_RIGHT_ARROW); // Right key
  } else {
    Keyboard.release(KEY_LEFT_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);
  }

  // Button
  if (isPressed) {
    Serial.println("button pressed");
    Keyboard.press('\\'); // '\\' key, rebind to any key
  } else {
    Keyboard.release('\\');
  }
  
  delay(50); // Small delay for stability
}