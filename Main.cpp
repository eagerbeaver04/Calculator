#include "Core.h"


int main(int argc, char** argv)
{
	std::string catalog = "./plugins";
	std::string extension = ".dll";
	Calculator* s = Calculator::getInstance(catalog, extension);
	s->calculating("^", 1.2, 2.5);
	std::cout << std::endl;

	//map<string, Operator*> operation_list;
	//loadDll(operation_list, catalog, extension);
	const std::string input = "4 * 1+ 2 - 3 * (5 + 6) *  7 + 8 ^ 3 * 4";
	std::string output;
	std::cout << "input: " << input << std::endl;
	if (s->operaions_map->shuntingYard(input, output)) {
		std::cout << "output: " << output << std::endl;
		s->operaions_map->executionOrder(output);
	}
	std::cout << std::endl;
	return 0;

	
}