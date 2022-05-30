#pragma once
#include "Figure.h"
#include <fstream>
class Circle :
	public Figure
{
	double r;
	std::string fill;

public:
	Circle(double cx, double cy, double r, const std::string& _fill, double stroke = 0, const std::string& strokeWidth = "none");
	
	friend std::ostream& operator << (std::ostream& out, const Circle& circle);	
	
	friend std::ofstream& operator << (std::ofstream& out, Circle& circle);
};

