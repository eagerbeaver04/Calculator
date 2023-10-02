#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Parser.h"

class Calculator 
{
public:
	static Calculator* getInstance(const std::string& folder_path, const std::string& extension)
	{
		static Calculator* instance = new Calculator(folder_path, extension);
		return instance;
	}
	void setInput(const std::string& input)
	{
		this->input = input;
	}
	void calculation()
	{
		if (this->operations_map->shuntingYard(this->input, this->output))
			this->operations_map->executionOrder(this->output);
	}
private:
	Parser* operations_map;
	std::string input;
	std::string output;
	Calculator(const std::string& folder_path, const std::string& extension)
	{
		this->operations_map = new Parser(folder_path, extension);
		this->input = "";
		this->output = "";
	};
	~Calculator() 
	{
		delete operations_map;
	};
	Calculator(const Calculator&);
	Calculator& operator= (const Calculator&) {};
};

#endif