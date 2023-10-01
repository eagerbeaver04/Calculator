#pragma once
#ifndef SORTER_H
#define SORTER_H

#include "Operations.h"
#include <sstream>
#include <stack>

class Parser
{
public:
	static Parser* getInstance(const std::string& folder_path, const std::string& extension)
	{
		static Parser* instance = new Parser(folder_path, extension);
		return instance;
	}
	bool shuntingYard(const std::string& input, std::string& output);
	bool executionOrder(const std::string& input);
	double calculation(std::string symbol, double a, double b);
private:
	Operations* operaions_map;
	Parser()
	{
		this->operaions_map = new Operations();
	}
	Parser(const std::string& folder_path, const std::string& extension)
	{
		this->operaions_map = new Operations(folder_path, extension);
	}
	~Parser() {};
	Parser(const Parser&);
	int opPriority(std::string symbol);
	bool opAssociativity(std::string c);
	int opBinary(std::string symbol);
	bool isOperator(std::string symbol);
	bool isFunction(std::string symbol);
	bool isIdent(std::string symbol);
	bool isIdent(char symbol);
	bool isLetter(char symbol);
	bool isLetter(std::string symbol);

};


#endif
