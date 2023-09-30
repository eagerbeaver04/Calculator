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
	double output()
	{
		return this->result;
	}
	void setInput(const std::string& input_)
	{
		this->expression = expression;
	}
	void calculating(const std::string& symbol, double a, double b)
	{
		std::cout << operaions_map->operaions_map->ñalculation(symbol, a, b);//example
	}
	Parser* operaions_map;
private:
	//Parser* operaions_map;
	std::string expression;
	double result;
	Calculator(const std::string& folder_path, const std::string& extension)
	{
		this->operaions_map = Parser::getInstance(folder_path, extension);
		this->expression = "";
		this->result;
	};
	void* getOperationBySymbol(const std::string& symbol);
	std::string getNameBySymbol(const std::string& symbol);
	int getPriorityBySymbol(const std::string& symbol);
	bool getAssociativityBySymbol(const std::string& symbol);
	int getBinaryBySymbol(const std::string& symbol);
	~Calculator()  = default;
	Calculator(const Calculator&);
	Calculator& operator= (const Calculator&) {};
};

#endif