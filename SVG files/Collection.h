#pragma once
#include "Circle.h"
#include "StraightLine.h"
#include "Rectangle.h"
#include "Figure.h"
#include <vector>
#include "CommandLineArguments.h"
class Collection
{
private:
	//Vector for storing figures
	std::vector <Figure*> figures;
public:

	Collection();
	//Print figures
	void print();
	//Create figure
	void create(CommandLineArguments& args);
	//Create figure
	void create(char* line);
	//Delete figure
	void erase(size_t index);
	//Translate figure
	void translate(size_t index);
	//Is empty
	bool isEmpty();

	friend std::ofstream& operator << (std::ofstream& out, Collection& col);
};

