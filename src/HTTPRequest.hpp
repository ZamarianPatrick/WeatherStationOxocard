#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <WString.h>
#include "WebServer.hpp"

using namespace std;

enum RequestMethod{
    GET,
    POST
};

class HTTPRequest{
    public:
        HTTPRequest(unsigned char *buffer, int len);
        ~HTTPRequest();
        RequestMethod method;
        string path;
        string protocol;

    protected:
        
    private:
};

#endif