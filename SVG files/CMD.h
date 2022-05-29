#pragma once
#include "Collection.h"
#include "CommandLineArguments.h"
class CMD
{
private:
	CMD();

public:
	CMD(const CMD&) = delete;
	CMD& operator= (const CMD&) = delete;

	static CMD& program();
	void run();

};

