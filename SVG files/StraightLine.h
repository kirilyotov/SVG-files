#pragma once
#include "Figure.h"
#include <fstream>

class StraightLine :
    public Figure
{//points
    Point2D secPoint;

public:
    StraightLine(double x, double y, double x2, double y2, double strokeWidth , const std::string& stroke );
    //output stream for console
    friend std::ostream& operator << (std::ostream& out, const StraightLine& line);
    //output stream for file
    friend std::ofstream& operator << (std::ofstream& out, StraightLine& line);
};

