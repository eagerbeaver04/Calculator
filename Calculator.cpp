#include "Calculator.h"


int main(int argc, char** argv)
{
	std::string catalog = "..\\plugins";
	std::string extension = ".dll";
	Calculator* app = app->getInstance(catalog, extension);
	while (true)
	{
		std::string input;
		std::getline(std::cin, input);
		app->setInput(input);
		app->calculation();
	}

}