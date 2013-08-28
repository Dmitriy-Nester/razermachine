#include "RMPathMaster.h"
extern "C"
{
    void* malloc(size_t);
    void free(char[]);
}

RMPathMaster::RMPathMaster(char path[])
{
    MainPath = std::string(path);
    unsigned int last = static_cast<unsigned int>(strlen(path));
    char *buf;
    while (last--)
    {
        this->slash = last;
        buf = &path[last];
        last*=(*buf=='/'||*buf=='\\');
    }
    slash = path - buf;
}

const char* RMPathMaster::relativePath(char path[])
{
   char* value = paths.find(std::string(path))->second;
   if(!value)
   {
       value = static_cast<char*>(malloc(slash+strlen(path)+1));
       memcpy(value, MainPath.c_str(), slash);
       memcpy(&value[slash+1], path, strlen(path));
       paths.insert(std::pair<std::string,char*>(std::string(path), value));
   }
   return  value;
}

RMPathMaster::~RMPathMaster()
{
    std::map<std::string, char*>::iterator itera = paths.begin();
    do
    {
        free(itera->second);
        itera++;
    }
    while(itera!=paths.end());
}