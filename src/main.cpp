#include <Arduino.h>


void setup() {
  Serial.begin(115200);  // Start serial communication
}

void loop() {
  Serial.println("ESP32 with PlatformIO is working!");  // Print message to Serial Monitor
  delay(1000);  // Wait 1 second
}
/*// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
} */