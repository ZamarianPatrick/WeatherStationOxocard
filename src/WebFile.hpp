#ifndef WEB_FILE_H
#define WEB_FILE_H

#include <string>

using namespace std;

class WebFile{

    public:

        WebFile(const char *contentType, const unsigned char *content, int len);
        ~WebFile();

        const char *getResponse();

    protected:

    private:
        string contentType;
        string content;
        string response;

    protected:

    private:

};

#endif