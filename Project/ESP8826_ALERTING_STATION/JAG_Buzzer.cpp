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


void JAG_Buzzer::animalBuzz() {
  //3 Buzzes
     Serial.println("Animal Alert");
  delay(500);
   digitalWrite(pin_, LOW);
    delay(500);
   digitalWrite(pin_, HIGH);
   delay(500);
   digitalWrite(pin_, LOW);
  delay(500);
   digitalWrite(pin_, HIGH);
    delay(500);
   digitalWrite(pin_, LOW);
   delay(500);
   digitalWrite(pin_, HIGH);
    delay(500);
   digitalWrite(pin_, LOW);

}

void JAG_Buzzer::carBuzz() {
   //2 Buzzes
   Serial.println("Car Alert");
  delay(500);
   digitalWrite(pin_, LOW);
    delay(500);
   digitalWrite(pin_, HIGH);
   delay(500);
   digitalWrite(pin_, LOW);
  delay(500);
   digitalWrite(pin_, HIGH);
    delay(500);
   digitalWrite(pin_, LOW);

}

void JAG_Buzzer::personBuzz() {
  // one long buzz
  Serial.println("Person Alert");
   digitalWrite(pin_, HIGH);
   delay(3000);
   digitalWrite(pin_, LOW);

}
