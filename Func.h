#ifndef FUNC_H
#define FUNC_H

#include <iostream>
using namespace std;
class Operator
{
public:
	Operator(const string& name, int prority, double (*operation) (double a, double b))
	{
		this->name = name;
		this->priority = priority;
		this->operation = operation;
	}
	Operator() = default;
	~Operator() = default;

	int getPriority()
	{
		return this->priority;
	}
	string getName()
	{
		return this->name;
	}
	void *getOperation()
	{
		return this->operation;
	}
private:
	string name;
	int priority;
	double (*operation)(double, double);
	Operator(const Operator& A);
	Operator& operator = (const Operator& A);
};

double sum(double a, double b)
{
	return a + b;
}

double sub(double a, double b)
{
	return a - b;
}

double mul(double a, double b)
{
	return a * b;
}

double div_(double a, double b)
{
	if (b != 0)
		return a / b;
	cerr << "Division by zero" << endl;
}

#endif