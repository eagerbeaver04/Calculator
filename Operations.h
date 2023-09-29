#pragma once
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Loader.h"

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
	std::cerr << "Division by zero" << std::endl;
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
	Operations(const std::string& folder_path, const std::string& extension): Operations()
	{
		Loader* loader = Loader::getInstance(folder_path, extension);
		loader->loadDll(this->operation_list, folder_path, extension);
	};

	void *getOperation(const std::string& symbol);
	std::string getName(const std::string& symbol);
	int getPriority(const std::string& symbol);
	bool getAssociativity(const std::string& symbol);
	int getBinary(const std::string& symbol);

	double ñalculation(const std::string& symbol, double a, double b);

	Operations& operator= (const Operations&) = default;
	~Operations() = default;
private:
	std::map<std::string, Operator*> operation_list;
	Operations(const Operations&);
};

#endif
