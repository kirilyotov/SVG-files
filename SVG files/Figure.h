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
    
   /* virtual void create() const = 0;
    virtual void erase(size_t index) const = 0;
    virtual void translate(size_t index) const = 0;
    virtual std::vector<Figure> within (bool (*cmp)(const Figure&) ) const = 0;
    */
};

