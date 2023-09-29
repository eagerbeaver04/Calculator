#pragma once
#ifndef SORTER_H
#define SORTER_H

#include <iostream>

class Sorter
{
public:
	void setInput(const std::string& input_)
	{
		this->input = input;
	}
	static Sorter& getInstance()
	{
		static Sorter instance;
		return instance;
	}

private:
	std::string input;
	Sorter();
	~Sorter() {};
	Sorter(const Sorter&);
	Sorter& operator= (const Sorter&);
};

#endif
