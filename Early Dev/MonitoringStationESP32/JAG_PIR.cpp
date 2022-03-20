#include "Arduino.h"
#include "JAG_PIR.h"

// initialise

JAG_PIR::JAG_PIR(int pin, bool logSerial)
{
 logSerial_ = logSerial;
 pin_ = pin;
 pinMode(pin_,INPUT);
}

// Public Functions

bool JAG_PIR::isMovementDetected() {
  bool isDetected = digitalRead(pin_);
  if(isDetected){
    if (logSerial_) {
      Serial.println("Presence detected");
    }
  } else {
      if (logSerial_) {
      Serial.println("NO Presence detected");
    }
  }
  delay(500);
  return isDetected;
}
