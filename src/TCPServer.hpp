#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <list>
#include <map>
#include <iostream>

#include <OXOcardRunner.h>

using std::string;
using std::cout;
using std::list;

class TCPServer{

    public:
        TCPServer(int port);
        ~TCPServer();

        void begin(bool newTask);
        void loop();

    protected:
        list <WiFiClient> clients;

        virtual void read() = 0;
        
    private:
        static int taskCount;
        int port = 80;
        WiFiServer server;

        void handleClients();

        static void handleClientsImpl(void *_this);

};

#endif