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
	s->calculating("sin", 2, 0);
	std::cout << std::endl;

	const std::string input = " 4! + sin(0 + sin(3.14)) + 5^(2 * 3 - 4) - 14 / 2";
	s->setInput(input);
	s->calculation();
	std::cout << std::endl;
	return 0;

	
}