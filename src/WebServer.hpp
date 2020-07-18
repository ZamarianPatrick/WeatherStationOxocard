#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <list>
#include <map>
#include <iostream>

#include <OXOcardRunner.h>
#include "TCPServer.hpp"
#include "WebFile.hpp"
#include "WebFiles.hpp"

#define REQUEST_BUFFER_SIZE 1000

class WebServer : public TCPServer{

    public:
        WebServer(int port);
        ~WebServer();

        void serve(const char *url, const char *filename);

    protected:
        void read() override;

    private:
        WebFiles webFiles;
        std::map <string, string> serves;

        void handleRequest(WiFiClient client, unsigned char *buffer, int len);
};

#endif