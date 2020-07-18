#include <iostream>
#include "HTTPRequest.hpp"

vector<string> split(const string& str, const string& delim){
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

HTTPRequest::HTTPRequest(unsigned char *buffer, int len){
    string s(reinterpret_cast<char const*>(buffer), len);
    
    string delimiter = "\n";
    vector<string> lines = split(s, delimiter);


    if(lines.size() > 0){
        string first = lines.at(0);
        delimiter = " ";
        vector<string> args = split(first, delimiter);
        
        if(args.size() >= 3){
            string method = args.at(0);
            if(method == "POST"){
                this->method = POST;
            }else{
                this->method = GET;
            }
            this->path = args.at(1);
            this->protocol = args.at(2);
        }
    }
}

HTTPRequest::~HTTPRequest(){

}