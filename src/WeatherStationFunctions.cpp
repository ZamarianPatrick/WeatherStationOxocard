#include <sys/time.h>

#include "WeatherStationFunctions.hpp"


WebServer WeatherStationFunctions::server = WebServer(80);
WebSocketsServer WeatherStationFunctions::websocketServer = WebSocketsServer(5567);
int WeatherStationFunctions::appState = 0;

char WeatherStationFunctions::viewTxt[200];
bool WeatherStationFunctions::textDisplayed = true;

const char *town = "66310";
long long WeatherStationFunctions::timestamp = 0; 

void WeatherStationFunctions::wsOnConnect(uint8_t num){
    
    switch (appState){
        case CMD_TEMPERATURE:
            sendTemperature(num);
            break;
        
        case CMD_HUMIDITY:
            sendHumidity(num);
            break;
        
        case CMD_TIME:
            sendTime(num);
            break;
        
        default:
            break;
    }
}

void WeatherStationFunctions::onWebSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type){
        case WStype_DISCONNECTED:
            break;

        case WStype_CONNECTED:
            wsOnConnect(num);
            break;

        case WStype_TEXT:
            break;

        default:
            break;
    }

}

void WeatherStationFunctions::onButtonClick(ButtonEventCallback *event){

    switch(event->getButton()){
        case L1:
            setAppState(CMD_TEMPERATURE);
            break;
        
        case L2:
            setAppState(CMD_HUMIDITY);
            break;

        case L3:
            setAppState(CMD_TIME);
            break;

        default:
            break;
    }
}

void WeatherStationFunctions::startWebServer(){
    
    oxocard.buttonEvent->clickCallback(L1, onButtonClick);
    oxocard.buttonEvent->clickCallback(L2, onButtonClick);
    oxocard.buttonEvent->clickCallback(L3, onButtonClick);
    oxocard.buttonEvent->clickCallback(R1, onButtonClick);
    oxocard.buttonEvent->clickCallback(R2, onButtonClick);
    oxocard.buttonEvent->clickCallback(R3, onButtonClick);

    server.serve("404", "404.html");
    server.serve("/", "index.html");
    server.serve("/home", "index.html");

    server.begin(false);
    websocketServer.begin();
    websocketServer.onEvent(onWebSocketEvent);
}


void displayTextImpl(void *args){

    int state = *((int *) args);

    if(WeatherStationFunctions::textDisplayed){
        WeatherStationFunctions::textDisplayed = false;
        oxocard.matrix->clear();
        if(state == 0 || state == 1){
            oxocard.matrix->drawImage(oxocard.weather->getDrawableIcon());
            vTaskDelay(500);
        }
        oxocard.matrix->drawText(WeatherStationFunctions::viewTxt, false);
        WeatherStationFunctions::textDisplayed = true;
    }

    vTaskDelete(NULL);
}

void WeatherStationFunctions::displayText(){
    
    switch (appState){
    case CMD_TEMPERATURE:
        sprintf(viewTxt, "%0.1f C", oxocard.weather->getTemperature());
        break;
    
    case CMD_HUMIDITY:
        sprintf(viewTxt, "%0.1f %", oxocard.weather->getHumidity());
        break;

    case CMD_TIME:
        sprintf(viewTxt, "%i:%i", oxocard.clock->getHour(), oxocard.clock->getMinute());
        break;

    default:
        break;
    }

    if(textDisplayed){
        xTaskCreate(
        displayTextImpl,
        "displayText",
        1000,
        &appState,
        1,
        NULL);
    }
}

void WeatherStationFunctions::refreshData(){
    timestamp = getCurrentMillis();
    if(appState == CMD_TEMPERATURE || appState == CMD_HUMIDITY) oxocard.weather->downloadWeatherForTown(town);
    sendData();
}

void WeatherStationFunctions::sendData(){
    switch (appState){
        case CMD_TEMPERATURE:
            sendTemperature();
            break;
        
        case CMD_HUMIDITY:
            sendHumidity();
            break;

        case CMD_TIME:
            sendTime();
            break;

        default:
            break;
    }
}

void getTimeTXT(char *txt){
    sprintf(txt, "%i;%i:%i", CMD_TIME, oxocard.clock->getHour(), oxocard.clock->getMinute());
}

void WeatherStationFunctions::sendTime(){
    char txt[50];
    getTimeTXT(txt);
    websocketServer.broadcastTXT(txt);
}

void WeatherStationFunctions::sendTime(uint8_t num){
    char txt[50];
    getTimeTXT(txt);
    websocketServer.sendTXT(num, txt);
}

void getHumidityTXT(char *txt){
    sprintf(txt, "%i;%0.1f;%i", CMD_HUMIDITY, oxocard.weather->getHumidity(), oxocard.weather->getIcon());
}

void WeatherStationFunctions::sendHumidity(){
    char txt[50];
    getHumidityTXT(txt);
    websocketServer.broadcastTXT(txt);
}

void WeatherStationFunctions::sendHumidity(uint8_t num){
    char txt[50];
    getHumidityTXT(txt);
    websocketServer.sendTXT(num, txt);
}

void getTemperatureTXT(char *txt){
    sprintf(txt, "%i;%0.1f;%i", CMD_TEMPERATURE, oxocard.weather->getTemperature(), oxocard.weather->getIcon());
}

void WeatherStationFunctions::sendTemperature(){
    char txt[50];
    getTemperatureTXT(txt);
    websocketServer.broadcastTXT(txt);
}

void WeatherStationFunctions::sendTemperature(uint8_t num){
    char txt[50];
    getTemperatureTXT(txt);
    websocketServer.sendTXT(num, txt);
}

void WeatherStationFunctions::loop(){
    if(timestamp == 0) refreshData();
    else if(getCurrentMillis() - timestamp > 30000) refreshData(); 

    displayText();

    server.loop();
    websocketServer.loop();
}

int WeatherStationFunctions::getAppState(){
    return appState;
}

void WeatherStationFunctions::setAppState(int state){
    appState = state;
    sendData();
}

long long WeatherStationFunctions::getCurrentMillis(){
    struct timeval te; 
    gettimeofday(&te, NULL);
    long long milliseconds_ll = te.tv_sec*1000LL + te.tv_usec/1000;
    return milliseconds_ll;
}