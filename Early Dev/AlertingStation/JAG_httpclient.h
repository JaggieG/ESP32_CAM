/*
  JAG_httpclient.h - Library for http client on ESP8826
  Created by John Gerhardt  20/12/2021
*/

#ifndef JAG_httpclient_h
#define JAG_httpclient_h


#include "Arduino.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

class JAG_httpclient
{
  public:
    JAG_httpclient(bool logSerial);
    void makeHTTPRequest(String toURL);
  private:
     bool logSerial_;  
     HTTPClient http;
     WiFiClient wifiClient;
};

#endif
