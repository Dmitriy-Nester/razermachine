#include "RMPathMaster.h"
#include <iostream>
/*extern "C"
{
    void* malloc(size_t);
    void free(char[]);
}*/

RMPathMaster::RMPathMaster(char path[])
{
    MainPath = std::string(path);
    unsigned int last = static_cast<unsigned int>(strlen(path));
    char *buf;
    bool flag;
    while (last--)
    {
        this->slash = last;
        buf = &path[last];
        flag = (*buf=='/'||*buf=='\\');
        last*=!flag;
    }
    slash = buf - path;
    const char *r = MainPath.c_str();
    std::cout<<&r[slash]<<" slash at position = "<<slash<<std::endl;
}

const char* RMPathMaster::relativePath(char path[])
{
    char* value = paths[path];
   if(!value)
   {
       value = static_cast<char*>(malloc(slash+strlen(path)+1));
       memcpy(value, MainPath.c_str(), slash+1);
       memcpy(&value[slash+1], path, strlen(path));
       paths.insert(std::pair<std::string,char*>(std::string(path), value));
       std::cout<<value<<std::endl;
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