#ifndef WEATHER_STATION_FUNCTIONS_H
#define WEATHER_STATION_FUNCTIONS_H

#define CMD_TEMPERATURE 0
#define CMD_HUMIDITY 1
#define CMD_TIME 2

#include <OXOcardRunner.h>

#include "WebServer.hpp"
#include <WebSocketsServer.h>

class WeatherStationFunctions{

    public:
        static bool textDisplayed;
        static char viewTxt[200];
        
        static void startWebServer();
        static void loop();
        static int getAppState();
        static void setAppState(int state);

    private:
        static WebServer server;
        static WebSocketsServer websocketServer;
        static int appState;
        static long long timestamp;

        static void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);
        static void wsOnConnect(uint8_t num);
        static long long getCurrentMillis();
        static void refreshData();
        static void sendData();
        static void sendTemperature();
        static void sendTemperature(uint8_t num);
        static void sendHumidity();
        static void sendHumidity(uint8_t num);
        static void sendTime();
        static void sendTime(uint8_t num);
        static void displayText();
        static void onButtonClick(ButtonEventCallback *event);
};

#endif