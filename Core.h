#ifndef CORE_H
#define CORE_H
#include "Calculator.h"

class Core 
{
public:
	static void init();
	static bool isOpen();
	static void events();
	static void create();
private:
	static Calculator app;
};

#endif