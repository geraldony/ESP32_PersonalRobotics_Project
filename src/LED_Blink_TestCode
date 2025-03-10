#include <Arduino.h>

/******* The Blinking LED Test Code  */
 
/** A preprocessor directive that creates a text replacement for pin 2 before code runs. It doesn's store any val in memory.
  * Pre-processor directives should always be written on top before the setup or loop methods. */
#define LED_PIN 2


void setup() {
  // The setup function runs only once the ESP 32 is powered up

  pinMode(LED_PIN,OUTPUT); // initializing the pin as an output 
  // put your setup code here, to run once:

}

void loop() {
 // This is where the main code goes 
 
 digitalWrite(LED_PIN, HIGH); //writing the LED to be high(ON)

 delay(1000); // Delaying the LED for sometime so I can notice the change

 digitalWrite(LED_PIN, LOW); // Writing the  to  be LED LOW(OFF)
 
 delay(1000);
}

 