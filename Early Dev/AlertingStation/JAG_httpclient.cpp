#include "Arduino.h"
#include "JAG_httpclient.h"

// initialise

JAG_httpclient::JAG_httpclient(bool logSerial)
{
 logSerial_ = logSerial;
}

// Public Functions

void JAG_httpclient::makeHTTPRequest(String toURL) {
  http.begin(wifiClient, toURL);
  int httpCode = http.GET();
  String payload = http.getString();
    if (logSerial_) {
      Serial.println(payload);
    }
  http.end();
}
