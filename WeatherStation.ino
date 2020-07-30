#include <list>

#include <OXOcardRunner.h>

#include <wificonfiguration.h>
#include <wireless.h>

#include "src/WeatherStationFunctions.hpp"

using namespace std;

void setup() {
  Serial.begin(115200);

  oxocard.wifi->autoConnectWithoutRetries();

  oxocard.clock->setTimeZone(12);
  WeatherStationFunctions::start();

  Serial.println("My IP address:");
  Serial.println(WiFi.localIP());
}

void loop() {
  WeatherStationFunctions::loop();  
}
