#include "Point2D.h"

Point2D::Point2D(double _x, double _y) : x (_x) , y(_y) { }

double Point2D::getX() const
{
    return x;
}

double Point2D::getY() const
{
    return y;
}
