#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include "Operations.h"
using namespace std;

class Calculator 
{
public:
	static Calculator& getInstance()
	{
		static Calculator instance;
		return instance;
	}
	double output()
	{
		return this->result;
	}
	void setInput(const string& input_)
	{
		this->expression = expression;
	}
	void calculating(const string& symbol, double a, double b)
	{
		cout << ((double (*)(double, double))(this->getOperationBySymbol(symbol)))(a,b);//example
	}
private:
	Operations* operaions_map;
	string expression;
	double result;
	Calculator()
	{
		this->operaions_map = new Operations();
		this->expression = "";
		this->result;
	};
	void* getOperationBySymbol(const string& symbol);
	string getNameBySymbol(const string& symbol);
	int getPriorityBySymbol(const string& symbol);
	bool getAssociativityBySymbol(const string& symbol);
	int getBinaryBySymbol(const string& symbol);
	~Calculator()  = default;
	Calculator(const Calculator&);
	Calculator& operator= (const Calculator&) {};
};

#endif