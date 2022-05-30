#pragma once
#include "Figure.h"
#include <fstream>
class Rectangle :
    public Figure
{
    double width;
    double height;
    std::string fill;

public:
  
    Rectangle(double x, double y, double _width, double _height, const std::string& _fill, double stroke = 0, const std::string& strokeWidth = "none");
    
    friend std::ostream& operator << (std::ostream& out, const Rectangle& rectangle);
   
    friend std::ofstream& operator << (std::ofstream& out, Rectangle& rectangle);
};

