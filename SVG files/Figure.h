#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Point2D.h"
class Figure 
{
protected:
    //Points 
    Point2D points; 
    //Stroke
    std::string stroke;

    double strokeWidth;

public:
    //Constructor with params
    Figure(double x, double y, double _strokeWidth,const std::string& _stroke);
    virtual ~Figure() = default;
    
};

