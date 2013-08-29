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
                const char *s_path = this->PathMaster->relativePath(const_cast<char*>(foread.c_str()));
                cout<<"relative path="<<s_path<<endl;
                std::ifstream internal(s_path);
            }
            //cout<<foread<<endl;
        }
    }
}

RazerMachine::~RazerMachine()
{
    delete this->PathMaster;
}