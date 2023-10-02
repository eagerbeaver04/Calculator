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
	if (!b)
		throw std::exception();
	return a / b;
}

class Operations
{
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

	int getPriority(const std::string& symbol);
	bool getAssociativity(const std::string& symbol);
	int getBinary(const std::string& symbol);

	double ñalculation(const std::string& symbol, double a, double b);
	~Operations() {
		for (auto& op : operation_list)
			delete op.second;
		operation_list.clear();
	}
private:
	std::map<std::string, Operator*> operation_list;
};

#endif
