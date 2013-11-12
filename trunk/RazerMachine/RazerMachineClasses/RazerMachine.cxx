#include "RazerMachine.h"
#include <fstream>
#include <iostream>
using namespace std;

RazerMachine::RazerMachine(char path[])
{
    noError = 1;
    this->PathMaster = new RMPathMaster(path);
    std::ifstream file(path);
    if(!file)
        printf("Error!!!\n");
    else
    {
        string foread;
        while(!file.eof()&&noError)
        {
            file>>foread;
            if(foread=="openfile")
            {
                 file>>foread;
                 this->OpenSubModule(foread.c_str());
            }
            else
                this->readOtherStructure(&foread, &file);
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
    //printf(">>>> result %s", !hile[0]?"ERROR":"SUCCESS");
    string buffer;
    while (!hile[0].eof()&&noError)
    {
        hile[0]>>buffer;
        if(buffer=="openfile")
        {
            hile[0]>>buffer;
            this->OpenSubModule(buffer.c_str());
        }
        else
            this->readOtherStructure(&buffer, hile);
    }
}

void RazerMachine::readOtherStructure(string* nowRead, basic_istream<char>* file)
{
    char v[64], b = 0;
    unsigned short int i = 1;
    file->read(&v[0], 1);//
    do
    {
        file->read(&b,1);
        v[i] = b;
        i++;
      //  printf("%c<>%i<>%i<%i>\n", b, int(b), int(i), int(' '));
    }
    while(b!='#'&&b!=' '&&b!=';'&&b!='\n'&&i!=63);
    v[i] = 0;
    printf("%s %s\n", nowRead->c_str(), v);
}

RazerMachine::~RazerMachine()
{
    delete this->PathMaster;
}