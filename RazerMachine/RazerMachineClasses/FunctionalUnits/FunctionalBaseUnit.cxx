#include "stdint.h"
#include "FunctionalBaseUnit.hxx"
#include "CallerStub/CallerStub.h"

FunctionalBaseUnit * FunctionalBaseUnit::Action()
{
	return nullptr;
}

void FunctionalBaseUnit::ActionUnit::Action(char *retextarct)
{
    if(this->ReturnValueType && retextarct)
    {
    }
}
