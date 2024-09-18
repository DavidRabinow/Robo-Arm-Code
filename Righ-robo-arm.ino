#include <Servo.h>

#define BTN_PIN_RIGHT 13   // New button pin for the right side
#define SERVO3_PIN    11   // New servo pin for servo3
#define SERVO4_PIN    9   // New servo pin for servo4

Servo servo3;
Servo servo4;
int buttonStateRight = 0;
int lastButtonStateRight = 0;
bool servosActivatedRight = false;

void setup() {
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);
  
  pinMode(BTN_PIN_RIGHT, INPUT_PULLUP);
  servo3.write(0);    // Set initial position of servo3 to 0 degrees
  servo4.write(180);  // Set initial position of servo4 to 180 degrees
}


void loop() {
  buttonStateRight = digitalRead(BTN_PIN_RIGHT);

  if (buttonStateRight == HIGH && lastButtonStateRight == LOW) {
    // Button is pressed
    if (!servosActivatedRight) {
      servo3.write(14);  // Move servo3 to 100 degrees
      servo4.write(60);   // Move servo4 to 60 degrees
      servosActivatedRight = true;
    } else {
      servo3.write(180);   // Return servo3 to 30 degrees
      servo4.write(180);  // Return servo4 to 180 degrees
      servosActivatedRight = false;
    }
  }

  lastButtonStateRight = buttonStateRight;
}
