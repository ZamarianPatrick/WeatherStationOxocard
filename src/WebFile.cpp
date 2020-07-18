#include <string.h>
#include <stdio.h>
#include <iostream>

#include "WebFile.hpp"

WebFile::WebFile(const char *contentType, const unsigned char *content, int len){
    string c(reinterpret_cast<char const*>(content), len);

    this->content = c;
    this->contentType = string(contentType);   
    
    char header[200];
    
    sprintf(header, "HTTP/1.1 200 OK\r\n" \
    "Access-Control-Allow-Origin: *\r\n" \
    "Content-type: %s\r\n" \
    "Connection: close\r\n" \
    "\r\n", contentType);
    
    this->response = string(header, strlen(header)) + this->content;
}

WebFile::~WebFile(){

}

const char *WebFile::getResponse(){
    return this->response.c_str();
}