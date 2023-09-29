#include "Operations.h"

void* Operations::getOperation(const std::string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getOperation();
	std::cerr << "Unavaliable operation: " << symbol << std::endl;
	return *sum;
	//add reset input string
}

std::string Operations::getName(const std::string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getName();
	std::cerr << "Unavaliable operation: " << symbol << std::endl;
	return "sum";
}

int Operations::getPriority(const std::string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getPriority();
	std::cerr << "Unavaliable operation: " << symbol << std::endl;
	return 1;
}

bool Operations::getAssociativity(const std::string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getAssociativity();
	std::cerr << "Unavaliable operation: " << symbol << std::endl;
	return true;
}

int Operations::getBinary(const std::string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getBinary();
	std::cerr << "Unavaliable operation: " << symbol << std::endl;
	return 2;
}

double Operations::ñalculation(const std::string& symbol, double a, double b)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->calculation(a,b);
	return 0;
}