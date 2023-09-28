#include "Operations.h"
#include <iostream>
#include <map>
using namespace std;

int main()
{
	Operations& s = Operations::getInstance();
	void* sum_ptr =  s.getOperationBySymbol("+");
	using eval_type = double (*)(double, double);
	eval_type sum = reinterpret_cast<eval_type>(sum_ptr);
	cout << sum(1, 2);
}