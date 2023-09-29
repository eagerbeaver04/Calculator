#include "Operations.h"

void* Operations::getOperation(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getOperation();
	cerr << "Unavaliable operation: " << symbol << endl;
	return *sum;
	//add reset input string
}

string Operations::getName(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getName();
	cerr << "Unavaliable operation: " << symbol << endl;
	return "sum";
}

int Operations::getPriority(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getPriority();
	cerr << "Unavaliable operation: " << symbol << endl;
	return 1;
}

bool Operations::getAssociativity(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getAssociativity();
	cerr << "Unavaliable operation: " << symbol << endl;
	return true;
}

int Operations::getBinary(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getBinary();
	cerr << "Unavaliable operation: " << symbol << endl;
	return 2;
}

