/*
  JAG_webserver.h - Library for handling web server for ESP8826
  Created by John Gerhardt  10/10/2021
*/

#ifndef JAG_webserver_h
#define JAG_webserver_h

#include "Arduino.h"
#include <ESP8266WebServer.h>

class JAG_webserver
{
  public:
    JAG_webserver(int port, bool logSerial);
    void setup();
    void runServerInLoop();
    void setupRoutes();
    ESP8266WebServer webserver;
    String get404PageContents();
    String getRootPageContents();
    String createHTMLpageWithContent_(String theContent);
    String createHTMLpageWithContentRaw_(String theContent);
    bool getAlertStatusPERSON();
    bool getAlertStatusCAR();
    bool getAlertStatusANIMAL();
    void setAlertStatusPERSON(bool ALERT_RECEIVED);
    void setAlertStatusCAR(bool ALERT_RECEIVED);
    void setAlertStatusANIMAL(bool ALERT_RECEIVED);
  private:
    int port_;
    bool logSerial_;
    bool ALERT_RECEIVED_PERSON_;
    bool ALERT_RECEIVED_CAR_;
    bool ALERT_RECEIVED_ANIMAL_;
    unsigned long millisAtLastAlert;
};

#endif
