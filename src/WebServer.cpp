#include "WebServer.hpp"
#include "HTTPRequest.hpp"

WebServer::WebServer(int port = 80) : TCPServer(port){

}

WebServer::~WebServer(){

}

void WebServer::handleRequest(WiFiClient client, unsigned char *buffer, int len){
    HTTPRequest http = HTTPRequest(buffer, len);
    std::map<string, string>::const_iterator pos = this->serves.find(http.path);
    
    bool sideFound = false; 

    if(pos != this->serves.end()){
        string filename = pos->second;
        
        WebFile webFile = this->webFiles.getFile(filename);

        const char *resp = webFile.getResponse();

        if(resp != NULL){
            sideFound = true;
            client.write(resp, strlen(resp));
            
            close(client.fd());

            client.flush();
            client.stop();
        }
    }

    if(sideFound == false){
        WebFile webFile = this->webFiles.getFile("404.html");

        const char *resp = webFile.getResponse();

        if(resp != NULL){
            client.write(resp, strlen(resp));
            close(client.fd());
            client.flush();
            client.stop();
        }
    }
}

void WebServer::serve(const char *url, const char *filename){
    this->serves.insert(pair<string, string>(string(url), string(filename)));  
}

void WebServer::read(){
    list <WiFiClient> :: iterator it;

    list <WiFiClient> toRemove;

    for(it = this->clients.begin(); it != this->clients.end(); ++it){
        WiFiClient client = *it;
        if(!client.connected()){
            toRemove.push_back(client);
            continue;
        }
        unsigned char buffer[REQUEST_BUFFER_SIZE];
        int len = client.read(buffer, REQUEST_BUFFER_SIZE);

        if(len > 0){
            this->handleRequest(client, buffer, len);
        }
    }

    for(it = toRemove.begin(); it != toRemove.end(); ++it){
        WiFiClient client = *it;
        this->clients.remove(client);
    }

}