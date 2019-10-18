#include "stdint.h"
#include "CallerStub.h"

void __fastcall fastcallslot(size_t argSize, char argRaw[], char retRxtract[], void* function)
{
    ;
}

void __fastcall stdcallslot(size_t argSize, char argRaw[], char retRxtract[], void* function)
{
    // TODO - need better solution
    __asm
    {
        mov EBX, argSize
        test EBX, EBX
        jz calling
            mov EBX, 0
        begin:
           push [argRaw + EBX]
           inc EBX
           cmp argSize, EBX
           jne begin
        calling:
           call function
           mov dword ptr [retRxtract], eax
    }
}

void __fastcall thiscallslot(size_t argSize, char argRaw[], char retRxtract[], void* function)
{
    size_t* buf = (size_t*)argRaw;
    size_t _class = buf[0];
    argSize -= sizeof(_class);
    char *offset = argRaw[sizeof(_class)];
    __asm
    {
        mov EBX, argSize
        test EBX, EBX
        jz calling:

    calling:
        mov ECX, _class
        call function
    }
}