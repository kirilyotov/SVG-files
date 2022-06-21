#pragma once
#include "Figure.h"
#include <fstream>
class Circle :
	public Figure
{
	//radius
	double r;
	//color
	std::string fill;

public:
	//Constructor with parameters
	Circle(double cx, double cy, double r, const std::string& _fill, double stroke = 0, const std::string& strokeWidth = "none");
	
	//Output Stream for console
	friend std::ostream& operator << (std::ostream& out, const Circle& circle);	
	//Output Stream for file
	friend std::ofstream& operator << (std::ofstream& out, Circle& circle);
};

