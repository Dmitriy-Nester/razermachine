#include "RazerMachine.h"
#include <fstream>
#include <iostream>
using namespace std;

RazerMachine::RazerMachine(char path[])
{
    std::ifstream file(path);
    if(!file)
        printf("Error!!!\n");
    else
    {
        string foread;
        while(!file.eof())
        {
            file>>foread;
            cout<<foread<<endl;
        }
    }
}