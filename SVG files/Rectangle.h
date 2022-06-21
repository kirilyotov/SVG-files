#pragma once
#include "Figure.h"
#include <fstream>
class Rectangle :
    public Figure
{
    //parameters
    double width;
    double height;
    //color
    std::string fill;

public:
    //constructor with parameters
    Rectangle(double x, double y, double _width, double _height, const std::string& _fill, double stroke = 0, const std::string& strokeWidth = "none");
    //output stream for console
    friend std::ostream& operator << (std::ostream& out, const Rectangle& rectangle);
    //output stream for file
    friend std::ofstream& operator << (std::ofstream& out, Rectangle& rectangle);
};

