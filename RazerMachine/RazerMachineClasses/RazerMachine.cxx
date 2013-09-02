#include "RazerMachine.h"
#include <fstream>
#include <iostream>
using namespace std;

RazerMachine::RazerMachine(char path[])
{
    this->PathMaster = new RMPathMaster(path);
    std::ifstream file(path);
    if(!file)
        printf("Error!!!\n");
    else
    {
        string foread;
        while(!file.eof())
        {
            file>>foread;
            if(foread=="openfile")
            {
                 file>>foread;
                 this->OpenSubModule(foread.c_str());
            }
            //cout<<foread<<endl;
        }
    }
}

void RazerMachine::OpenSubModule(const char path[])
{
    const char *s_path = this->PathMaster->relativePath(const_cast<char*>(path));
    std::ifstream internal = std::ifstream(s_path);
    this->OpenSubModule(&internal);
}

void RazerMachine::OpenSubModule(std::basic_istream<char>* hile)
{
    //hile->fill();
    printf(">>>> result %s", !hile[0]?"ERROR":"SUCCESS");
    string g;
    hile[0]>>g;
    cout<<g<<endl;
}

RazerMachine::~RazerMachine()
{
    delete this->PathMaster;
}