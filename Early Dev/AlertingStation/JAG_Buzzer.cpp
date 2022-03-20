#include "Arduino.h"
#include "JAG_Buzzer.h"

// initialise

JAG_Buzzer::JAG_Buzzer(int pin, bool logSerial)
{
 logSerial_ = logSerial;
 pin_ = pin;
 pinMode(pin_,OUTPUT);
}

// Public Functions

void JAG_Buzzer::buzzForXSeconds(int seconds) {
   digitalWrite(pin_, HIGH);
   delay(seconds * 1000);
   digitalWrite(pin_, LOW);
}
