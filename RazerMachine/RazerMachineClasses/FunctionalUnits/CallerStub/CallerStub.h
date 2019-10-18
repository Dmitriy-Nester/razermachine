#ifndef _CALLERSUB_H_
#define _CALLERSUB_H_
#ifdef __cplusplus
extern "C"
{
#endif 
void __fastcall fastcallslot(size_t argSize, char argRaw[], char retRxtract[], void* function);
void __fastcall stdcallslot(size_t argSize, char argRaw[], char retRxtract[], void* function);
void __fastcall thiscallslot(size_t argSize, char argRaw[], char retRxtract[], void* function);
#ifdef __cplusplus
}
#endif 
#endif