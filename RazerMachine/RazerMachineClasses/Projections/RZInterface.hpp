#ifndef _RZINTERFACE_HPP_
#define _RZINTERFACE_HPP_
#include <vector>
class RZInterface
{
	public:
	RZInterface(char[]);
	void* getMethodWithName(const char[]);
	void addMethod(const char[]);
	private:
	std::string name;
	std::vector<char*> methods, types;
    std::vector<unsigned long> argumentssizes;
};
#endif