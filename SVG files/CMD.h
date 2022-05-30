#pragma once

#include "Collection.h"
#include "CommandLineArguments.h"

class CMD
{
private:
	CMD();
	Collection collection;
	static const  std::string header;
	static const std::vector<std::string> integratedCommands;

	void isCorrectCommand(CommandLineArguments& lines);

	void open(std::string file); //0
	void close();//1
	void save();//2
	void saveAs(std::string directory);//3
	void help();//4
	void print();//5
	void exit();//6
	void create();//7
	void erase(size_t index);//8
	void translate(size_t index);//9
	void within();//10

	void writeToFile();
	void readFromFile();
	void createTemporaryFile();

public:
	CMD(const CMD& other) = delete;
	CMD& operator= (const CMD& other) = delete;

	static CMD& program();
	void run();

};

