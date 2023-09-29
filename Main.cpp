#include <Windows.h>
#include "Calculator.h"
#include "Loader.h"

using namespace std;

int main(int argc, char** argv)
{
	Calculator& s = Calculator::getInstance();
	s.calculating("+", 1.2, 2.5);

	string catalog = "./plugins";
	string extension = ".dll";

	map<string, Operator*> operation_list;
	loadDll(operation_list, catalog, extension);
	cout << endl;
	
}