#include "TCPServer.hpp"

int TCPServer::taskCount = 0;

TCPServer::TCPServer(int port){
    this->port = port;
    this->server = WiFiServer(port);
}

TCPServer::~TCPServer(){

}

void TCPServer::handleClientsImpl(void *_this){
    TCPServer *server = (TCPServer*) _this;
    server->handleClients();
}

void TCPServer::handleClients(){
    while(true){
        loop();
    }
}

void TCPServer::loop(){
    WiFiClient client = this->server.available();

    if(client){
        this->clients.push_back(client);
    }

    this->read();
}

void TCPServer::begin(bool newTask = true){
    this->server.begin();

    if(newTask){
        char name[16];
        sprintf(name, "tt%i", taskCount);
        xTaskCreate(
            this->handleClientsImpl,   // Task function. 
            name,     // name of task.
            10000,       // Stack size of task
            this,        // parameter of the task
            1,           // priority of the task
            NULL);      // Task handle to keep track of created task

        taskCount++;
    }
}