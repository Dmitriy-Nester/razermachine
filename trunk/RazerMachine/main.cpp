//
//  main.cpp
//  RazerMachine
//
//  Created by Quadecco on 8/23/13.
//  Copyright (c) 2013 Dima. All rights reserved.
//

#include <iostream>
#include "RazerMachineClasses/RazerMachine.h"

int main(int argc, const char * argv[])
{
#ifndef _MSC_VER
    char path[]= "/Users/kseniiapodoliaka/Documents/cc/RazerMachine/RazerMachine/RazerMachine/testmachine.txt";
#else
	char path[] = "../RazerMachine/testmachine.txt";
#endif
	RazerMachine Machine(path);
    return 0;
}

