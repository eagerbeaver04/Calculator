#ifndef SORTER_H
#define SORTER_H

#include "Operations.h"
#include <sstream>
#include <stack>

class Parser
{
public:
	bool shuntingYard(const std::string& input, std::string& output);
	bool executionOrder(const std::string& input);
	double calculation(std::string symbol, double a, double b);
	~Parser() 
	{
		delete  operations_map;
	}
	Parser()
	{
		this->operations_map = new Operations();
	}
	Parser(const std::string& folder_path, const std::string& extension)
	{
		this->operations_map = new Operations(folder_path, extension);
	}
private:
	Operations* operations_map;
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
