#include "Calculator.h"

void* Calculator::getOperationBySymbol(const string& symbol)
{
	return this->operaions_map->getOperation(symbol);
}

string Calculator::getNameBySymbol(const string& symbol)
{
	return this->operaions_map->getName(symbol);
}

int Calculator::getPriorityBySymbol(const string& symbol)
{
	return this->operaions_map->getPriority(symbol);
}

bool Calculator::getAssociativityBySymbol(const string& symbol)
{
	return this->operaions_map->getAssociativity(symbol);
}

int Calculator::getBinaryBySymbol(const string& symbol)
{
	return this->operaions_map->getBinary(symbol);
}