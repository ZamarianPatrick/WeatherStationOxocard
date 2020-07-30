#ifndef WEATHER_STATION_FUNCTIONS_H
#define WEATHER_STATION_FUNCTIONS_H

#include <OXOcardRunner.h>
#include <DHT.h>
#include <IRremote.h>

#include "WebServer.hpp"
#include <WebSocketsServer.h>

#define CMD_TEMPERATURE 0
#define CMD_HUMIDITY 1
#define CMD_TIME 2
#define CMD_ROOM_TEMPERATURE 3
#define CMD_ROOM_HUMIDITY 4

#define IR_1 16724175
#define IR_2 16718055
#define IR_3 16743045 
#define IR_4 16716015
#define IR_5 16726215
#define IR_6 16734885
#define IR_7 16728765
#define IR_8 16730805
#define IR_9 16732845
#define IR_STOP 16761405

#define IR_PIN 16
#define DHTPIN 17
#define DHTTYPE DHT22

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
        static DHT dht;
        static IRrecv ir;
        static decode_results results;
        static float roomTemperature;
        static float roomHumidity;


        static void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);
        static void wsOnConnect(uint8_t num);
        static long long getCurrentMillis();
        static void refreshData();
        static void sendData();
        static void sendTemperature();
        static void sendTemperature(uint8_t num);
        static void getRoomTemperatureTXT(char *txt);
        static void sendRoomTemperature();
        static void sendRoomTemperature(uint8_t num);
        static void sendHumidity();
        static void sendHumidity(uint8_t num);
        static void getRoomHumidityTXT(char *txt);
        static void sendRoomHumidity();
        static void sendRoomHumidity(uint8_t num);
        static void sendTime();
        static void sendTime(uint8_t num);
        static void displayText();
        static void onButtonClick(ButtonEventCallback *event);
        static void onIR(int value);
};

#endif