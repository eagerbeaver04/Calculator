#ifndef LOADER_H
#define LOADER_H

#include <Windows.h>
#include <map>
#include <vector>
#include <filesystem>
#include "Operator.h"
#include <vector>


class Loader
{
public:
	static Loader* getInstance(const std::string& folder_path, const std::string& extension)
	{
		static Loader* instance = new Loader(folder_path, extension);
		return instance;
	}
	Operator* getOperatorFromDll(std::filesystem::path path);
	void loadDll(std::map<std::string, Operator*>& operation_list, const std::string& folder_path, const std::string& extension);
private:
	std::vector< HINSTANCE> lib_list;
	std::string folder_path;
	std::string extension;

	Loader(const std::string& folder_path, const std::string& extension)
	{
		this->lib_list;
		this->folder_path = folder_path;
		this->extension = extension;
	}
	Loader()
	{
		this->lib_list;
		this->folder_path = "";
		this->extension = "";
	}
	~Loader()
	{
		for (auto& lib : lib_list)
			FreeLibrary(lib);
		lib_list.clear();
	}
};

#endif
