#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <map>
#include "Func.h"

static double sum(double a, double b)
{
	return a + b;
}

static double sub(double a, double b)
{
	return a - b;
}

static double mul(double a, double b)
{
	return a * b;
}

static double div_(double a, double b)
{
	if (b != 0)
		return a / b;
	cerr << "Division by zero" << endl;
	return a;
}

class Operations:public Operator {
public:
	Operations()
	{
		this->operation_list["+"] = new Operator("+", 1, true, 2, sum);
		this->operation_list["-"] = new Operator("-", 1, true, 2, sub);
		this->operation_list["*"] = new Operator("*", 2, true, 2, mul);
		this->operation_list["/"] = new Operator("/", 2, true, 2, div_);
	};
	void *getOperation(const string& symbol);
	string getName(const string& symbol);
	int getPriority(const string& symbol);
	bool getAssociativity(const string& symbol);
	int getBinary(const string& symbol);
	Operations& operator= (const Operations&) = default;
	~Operations() = default;
private:
	map<string, Operator*> operation_list;
	Operations(const Operations&);
	// add - directory iterator -> .dll проверка на файл и entry.path.extension
};

#endif
