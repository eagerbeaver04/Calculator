#ifndef FUNC_H
#define FUNC_H

#include <iostream>
using namespace std;
class Operator
{
public:
	Operator(const string& name, int priority, bool associativity, int binary, double (*operation) (double a, double b))
	{
		this->name = name;
		this->priority = priority;
		this->operation = operation;
		this->associativity = associativity;
		this->binary = binary;
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
	int getBinary()
	{
		return this->binary;
	}
	bool getAssociativity()
	{
		return this->associativity;
	}
	void *getOperation()
	{
		return this->operation;
	}
private:
	string name;
	int priority;
	bool associativity;// true - left, false - right
	int binary;
	double (*operation)(double, double);

	Operator(const Operator& A);
	Operator& operator = (const Operator& A);
};

#endif