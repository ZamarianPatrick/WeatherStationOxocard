#ifndef WEB_FILES_H
#define WEB_FILES_H

#include <map>
#include <string>

#include "WebFile.hpp"

class WebFiles{

    public:
        WebFiles();

        WebFile getFile(string name);

    protected:

    private:
        std::map <string, WebFile> files;
};

#endif