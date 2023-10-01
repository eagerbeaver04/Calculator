#pragma once
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
	void calculating(const std::string& symbol, double a, double b)
	{
		std::cout << operaions_map->calculation(symbol, a, b);// for tests
	}
	void calculation()
	{
		if (this->operaions_map->shuntingYard(this->input, this->output))
			this->operaions_map->executionOrder(this->output);
	}
private:
	Parser* operaions_map;
	std::string input;
	std::string output;
	Calculator(const std::string& folder_path, const std::string& extension)
	{
		this->operaions_map = Parser::getInstance(folder_path, extension);
		this->input = "";
		this->output = "";
	};
	~Calculator()  = default;
	Calculator(const Calculator&);
	Calculator& operator= (const Calculator&) {};
};

#endif