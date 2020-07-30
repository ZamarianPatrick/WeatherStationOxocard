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

void TCPServer::begin(){
    this->server.begin();
}

void TCPServer::end(){
    this->server.end();
}