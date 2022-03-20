/* Import the required modules */
#include "JAG_wificlient.h"
#include "JAG_webserver.h"
#include "JAG_PIR.h"
#include "JAG_LED.h"
#include "JAG_httpclient.h"


JAG_wificlient wifi_client = JAG_wificlient("CHALETEMMANUEL","LOCKEDDOWN", true);
JAG_webserver webserver = JAG_webserver(80, true);
JAG_PIR pir_sensor = JAG_PIR(4, false); // D2 GPIO4
JAG_LED LED_movement_detected = JAG_LED(5, false);// D1 GPIO5
JAG_httpclient httpClient = JAG_httpclient(true); // http client

// 192.168.1.123 on COM5 
void setup() {
  Serial.begin(115200);
  // setup WIFi
  wifi_client.connectToWireless();
  
  // setup Web Server
  webserver.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  webserver.runServerInLoop();
  
  bool MOVEMENT_DETECTED = pir_sensor.isMovementDetected();
  bool LED_ACTIVE;

  if (MOVEMENT_DETECTED) {
    LED_ACTIVE = true;
    webserver.updateMovementDetected();
    LED_movement_detected.turnOnLED();
    httpClient.makeHTTPRequest("http://192.168.1.122/alertMe");
    delay(5000); // to leave time for everything to catch up
  } else {
    LED_ACTIVE = false;
    LED_movement_detected.turnOffLED();
  }
   Serial.println("MOVEMENT_DETECTED");
   Serial.println(MOVEMENT_DETECTED);
   Serial.println("LED_ACTIVE");
   Serial.println(LED_ACTIVE);
  
}
