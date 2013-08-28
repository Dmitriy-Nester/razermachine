#ifndef _RMPATHMASTER_H_
#define _RMPATHMASTER_H_
#include <string>
#include <map>
class RMPathMaster
{
public:
    RMPathMaster(char[]);
    const char* relativePath(char[]);
    ~RMPathMaster();
private:
    size_t slash;
    std::string MainPath;
    std::map<std::string, char*> paths;
};
#endif