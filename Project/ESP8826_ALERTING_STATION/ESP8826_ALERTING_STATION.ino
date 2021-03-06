/* Import the required modules */
#include "JAG_wificlient.h"
#include "JAG_webserver.h"
#include "JAG_Buzzer.h"
#include "JAG_LED.h"
#include "JAG_httpclient.h"

// IP 192.168.1.122 on COM7

// Load the Wifi Client that handles connecting the board to the Wifi
JAG_wificlient wifi_client = JAG_wificlient("CHALETEMMANUEL","LOCKEDDOWN", true);

// Load the web server so that we can produce a web interface 
JAG_webserver webserver = JAG_webserver(80, true);

// Load the LED and buzer libraries to handles their usage
JAG_LED LED_alert_recieved = JAG_LED(5, false);// D1 GPIO5
JAG_Buzzer buzzer = JAG_Buzzer(4, false); // D2 GPIO4

// load the http client that will make http calls to other stations
JAG_httpclient httpClient = JAG_httpclient(true); // http client

// main setup routine (run one)
void setup() {
  Serial.begin(115200);
  // setup WIFi
  wifi_client.connectToWireless();
  
  // setup Web Server
  webserver.setup();

  buzzer.buzzForXSeconds(1); // so we know that the buzzer is working at startup
}

void loop() {
  webserver.runServerInLoop(); 
  bool ALERT_RECEIVED_PERSON = webserver.getAlertStatusPERSON();
  bool ALERT_RECEIVED_ANIMAL = webserver.getAlertStatusANIMAL();
  bool ALERT_RECEIVED_CAR = webserver.getAlertStatusCAR();


  if(ALERT_RECEIVED_PERSON) {
    
   LED_alert_recieved.turnOnLED();
         buzzer.personBuzz();
   LED_alert_recieved.turnOffLED();
   webserver.setAlertStatusPERSON(false);
  }

  if(ALERT_RECEIVED_ANIMAL) {
   LED_alert_recieved.turnOnLED();
       buzzer.animalBuzz();
   LED_alert_recieved.turnOffLED();
   webserver.setAlertStatusANIMAL(false);
  }

  if(ALERT_RECEIVED_CAR) {
   LED_alert_recieved.turnOnLED();
     buzzer.carBuzz();
   LED_alert_recieved.turnOffLED();
   webserver.setAlertStatusCAR(false);
  }

  
}
