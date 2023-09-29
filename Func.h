#pragma once
#ifndef FUNC_H
#define FUNC_H

#include <iostream>

class Operator
{
public:
	Operator(const std::string& name, int priority, bool associativity, int binary, double (*operation) (double a, double b))
	{
		this->name = name;
		this->priority = priority;
		this->operation = operation;
		this->associativity = associativity;
		this->binary = binary;
	}
	Operator() = default;
	~Operator() = default;
	Operator(const Operator& A) = default;
	Operator& operator = (const Operator& A) = default;

	int getPriority()
	{
		return this->priority;
	}
	std::string getName()
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
	double calculation(double a, double b)
	{	
		return (this->operation)(a, b);
	}
private:
	std::string name;
	int priority;
	bool associativity;// true - left, false - right
	int binary;
	double (*operation)(double, double);
};

#endif