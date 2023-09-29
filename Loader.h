#ifndef LOADER_H
#define LOADER_H
#include <Windows.h>
#include "Operations.h"
#include <vector>
#include <filesystem>

Operator* getFunction(filesystem::path path)
{
	const wchar_t* widecFileName = path.c_str();

	HINSTANCE load;
	load = LoadLibraryW(widecFileName);

	typedef double (*double_fun_2) (double, double);
	typedef int (*int_fun) (void);
	typedef string(*str_fun) (void);
	typedef bool (*bool_fun) (void);

	double_fun_2 Fun;
	int_fun Binary;
	int_fun Priority;
	str_fun Name;
	bool_fun Associativity;

	Fun = (double_fun_2)GetProcAddress(load, "operation");
	Binary = (int_fun)GetProcAddress(load, "binary");
	Priority = (int_fun)GetProcAddress(load, "priority");
	Name = (str_fun)GetProcAddress(load, "name");
	Associativity = (bool_fun)GetProcAddress(load, "associativity");

	Operator* op = new Operator(Name(), Priority(), Associativity(), Binary(), Fun);

	FreeLibrary(load);

	return op;
}

void loadDll(map<string, Operator*>& operation_list, const string& folder_path, const string& extension)
{
	vector<filesystem::path> files;

	for (auto& entry : filesystem::directory_iterator(folder_path))
		if (entry.path().extension() == extension)
			files.push_back(entry.path().c_str());

	for (auto& path : files)
		operation_list[getFunction(path)->getName()] = getFunction(path);
		
}

#endif
