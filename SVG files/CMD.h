#pragma once

#include "Collection.h"

class CMD
{
private:
	CMD();
	Collection collection;
	
	static const  std::string header;
	void print();
	void create();
	void erase(size_t index);
	void translate(size_t index);
	void within();
	void writeToFile();
	void readFromFile();
	void createTemporaryFile();

public:
	CMD(const CMD& other) = delete;
	CMD& operator= (const CMD& other) = delete;

	static CMD& program();
	void run();

};

