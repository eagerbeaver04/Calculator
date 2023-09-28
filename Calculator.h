#ifndef Calculator_H
#define Calculator_H

#include <iostream>
using namespace std;

class Calculator 
{
public:
	void setInput(const string& input_)
	{
		this->expression = expression;
	}
	static Calculator& getInstance()
	{
		static Calculator instance;
		return instance;
	}
	double output()
	{
		return this->result;
	}
	void calculating();
private:
	string expression;
	double result;
	Calculator() {};
	~Calculator() {};
	Calculator(const Calculator&);
	Calculator& operator= (const Calculator&) {};
};

#endif