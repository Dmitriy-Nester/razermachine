#ifndef _RAZERMACHINE_H_
#define _RAZERMACHINE_H_
#include <istream>
#include "RMPathMaster.h"
class RazerMachine
{
    public:
    RazerMachine(char path[]);
    //RazerMachine(char text[]);
    private:
    RMPathMaster* PathMaster;
    void OpenSubModule(char[]);
    void OpenSubModueL(std::basic_istream<char>*);
    public:
    ~RazerMachine();
};
#endif