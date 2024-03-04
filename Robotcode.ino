#include <Servo.h>

#define BTN_PIN   7
#define SERVO1_PIN  3
#define SERVO2_PIN  5

Servo servo1;
Servo servo2;
int buttonState = 0;
int lastButtonState = 0;
bool servosActivated = false;

void setup() {
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  
  pinMode(BTN_PIN, INPUT_PULLUP);
  servo1.write(0);  // Set initial position of servo1 to 15 degrees
  servo2.write(180);  // Set initial position of servo2 to 90 degrees
}

void loop() {
  buttonState = digitalRead(BTN_PIN);

  if (buttonState == HIGH && lastButtonState == LOW) {
    // Button is pressed
    if (!servosActivated) {
      servo1.write(100);  // Set servo1 to 90 degrees
      servo2.write(60); // Set servo2 to 180 degrees
      servosActivated = true;
    } else {
      servo1.write(-30);  // Return servo1 to 15 degrees
      servo2.write(180);  // Return servo2 to 90 degrees
      servosActivated = false;
    }
  }

  lastButtonState = buttonState;
}
