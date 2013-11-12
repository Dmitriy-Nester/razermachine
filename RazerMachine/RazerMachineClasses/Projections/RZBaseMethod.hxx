#ifndef _RZBASEMZT_HXX_
#define _RZBASEMZT_HXX_
struct RZBaseMethod
{
    private:
        void* pointer;
        size_t argsize;
    public:
    RZBaseMethod(const char[], size_t, void*, size_t); //razer name, size arguments, function pointer, returned size
};
#endif