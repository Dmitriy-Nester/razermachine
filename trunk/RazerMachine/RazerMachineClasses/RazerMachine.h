#ifndef _RAZERMACHINE_H_
#define _RAZERMACHINE_H_
#include <istream>
class RazerMachine
{
    public:
    RazerMachine(char path[]);
    //RazerMachine(char text[]);
    private:
    std::string MainPath;
    void OpenSubModule(char[]);
    void OpenSubModueL(std::basic_istream<char>*);
};
#endif