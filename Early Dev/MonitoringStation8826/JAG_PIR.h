/*
  JAG_PIR.h - Library for PIR sensor on ESP32
  Created by John Gerhardt  19/12/2021
*/

#ifndef JAG_PIR_h
#define JAG_PIR_h

#include "Arduino.h"

class JAG_PIR
{
  public:
    JAG_PIR(int pin, bool logSerial);
    bool isMovementDetected();
    int pin_;
  private:
     bool logSerial_;    
};

#endif
