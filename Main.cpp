#include "Core.h"


int main(int argc, char** argv)
{
	std::string catalog = "./plugins";
	std::string extension = ".dll";
	Calculator* s = Calculator::getInstance(catalog, extension);
	s->calculating("^", 1.2, 2.5);

	//map<string, Operator*> operation_list;
	//loadDll(operation_list, catalog, extension);
	std::cout << std::endl;
	
}