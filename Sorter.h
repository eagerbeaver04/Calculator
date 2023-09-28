#ifndef SORTER_H
#define SORTER_H

#include <iostream>
using namespace std;

class Sorter
{
public:
	void setInput(const string& input_)
	{
		this->input = input;
	}
	static Sorter& getInstance()
	{
		static Sorter instance;
		return instance;
	}

private:
	string input;
	Sorter();
	~Sorter() {};
	Sorter(const Sorter&);
	Sorter& operator= (const Sorter&);
};

#endif
