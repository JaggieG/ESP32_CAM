/*
  JAG_LED.h - Library for LED via GPIO sensor on ESP32
  Created by John Gerhardt  20/12/2021
*/

#ifndef JAG_LED_h
#define JAG_LED_h

#include "Arduino.h"

class JAG_LED
{
  public:
    JAG_LED(int pin, bool logSerial);
    void turnOffLED();
    void turnOnLED();
    int pin_;
  private:
     bool logSerial_;
     
};

#endif
