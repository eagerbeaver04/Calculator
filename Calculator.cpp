#include "Calculator.h"

void* Calculator::getOperationBySymbol(const std::string& symbol)
{
	return this->operaions_map->getOperation(symbol);
}

std::string Calculator::getNameBySymbol(const std::string& symbol)
{
	return this->operaions_map->getName(symbol);
}

int Calculator::getPriorityBySymbol(const std::string& symbol)
{
	return this->operaions_map->getPriority(symbol);
}

bool Calculator::getAssociativityBySymbol(const std::string& symbol)
{
	return this->operaions_map->getAssociativity(symbol);
}

int Calculator::getBinaryBySymbol(const std::string& symbol)
{
	return this->operaions_map->getBinary(symbol);
}