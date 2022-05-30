#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Point2D.h"
class Figure 
{
protected:
    Point2D points; 
    std::string stroke;
    double strokeWidth;

public:
    Figure(double x, double y, double _strokeWidth,const std::string& _stroke);
    virtual ~Figure() = default;
    
};

