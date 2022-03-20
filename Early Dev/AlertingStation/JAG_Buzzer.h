/*
  JAG_Buzzer.h - Library for Buzzer on ESP32
  Created by John Gerhardt  20/12/2021
*/

#ifndef JAG_Buzzer_h
#define JAG_Buzzer_h

#include "Arduino.h"

class JAG_Buzzer
{
  public:
    JAG_Buzzer(int pin, bool logSerial);
    void buzzForXSeconds(int seconds);
    int pin_;
  private:
     bool logSerial_;  
};

#endif
