#include "Core.h"


int main(int argc, char** argv)
{
	std::string catalog = "./plugins";
	std::string extension = ".dll";
	Calculator* s = Calculator::getInstance(catalog, extension);
	s->calculating("^", 1.2, 2.5);
	std::cout << std::endl;
	s->calculating("!", 4, 0);
	std::cout << std::endl;

	const std::string input = " 4! + sin(0 + sin(3.14)) + 5^(2 * 3 - 4) - 14 ";
	std::string output;
	std::cout << "input: " << input << std::endl;
	if (s->operaions_map->shuntingYard(input, output)) 
	{
		//std::cout << "output: " << output << std::endl;
		s->operaions_map->executionOrder(output);
	}
	std::cout << std::endl;
	return 0;

	
}