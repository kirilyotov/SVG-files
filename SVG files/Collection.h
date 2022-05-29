#pragma once
#include "Circle.h"
#include "StraightLine.h"
#include "Rectangle.h"
#include <vector>

class Collection
{
private:
	std::vector <Figure*> figures;
public:

	Collection();
	void print();
	void create();
	void erase(size_t index);
	void translate(size_t index);
	void within();
	bool isEmpty();
};

