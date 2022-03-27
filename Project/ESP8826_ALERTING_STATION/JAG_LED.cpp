#include "Arduino.h"
#include "JAG_LED.h"

// initialise

JAG_LED::JAG_LED(int pin, bool logSerial)
{
 logSerial_ = logSerial;
 pin_ = pin;
 pinMode(pin_,OUTPUT);
}

// Public Functions

void JAG_LED::turnOnLED() {
  digitalWrite(pin_, HIGH);
  if (logSerial_) {
    Serial.println("LED ON");
  }
}

void JAG_LED::turnOnLEDForXSeconds(int seconds) {
  digitalWrite(pin_, HIGH);
  delay(seconds * 1000);
  if (logSerial_) {
    Serial.println("LED ON");
  }
}

void JAG_LED::turnOffLED() {
  digitalWrite(pin_, LOW);
  if (logSerial_) {
    Serial.println("LED OFF");
  }
}
