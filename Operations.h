#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <map>
#include "Func.h"

class Operations:public Operator {
public:
	static Operations& getInstance()
	{
		static Operations instance;
		return instance;
	}
	void *getOperationBySymbol(const string& symbol);
	string getNameBySymbol(const string& symbol);
	int getPriorityBySymbol(const string& symbol);
private:
	map<string, Operator*> operation_list;
	Operations()
	{
		this->operation_list["+"] = new Operator("+", 1, *sum);
		this->operation_list["-"] = new Operator("-", 1, *sub);
		this->operation_list["*"] = new Operator("*", 2, *mul);
		this->operation_list["/"] = new Operator("/", 2, *div_);
	};
	~Operations() {};
	Operations(const Operations&);
	Operations& operator= (const Operations&) {};
	// add - directory iterator -> .dll проверка на файл и entry.path.axtension
};

void *Operations::getOperationBySymbol(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getOperation();
	cerr << "Unavaliable operation: " << symbol << endl;
}

string Operations::getNameBySymbol(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getName();
	cerr << "Unavaliable operation: " << symbol << endl;
}

int Operations::getPriorityBySymbol(const string& symbol)
{
	if (this->operation_list.count(symbol) == 1)
		return this->operation_list[symbol]->getPriority();
	cerr << "Unavaliable operation: " << symbol << endl;
}

#endif
