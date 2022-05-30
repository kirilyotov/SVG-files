#pragma once
class Point2D
{
protected:
	double x;
	double y;
public:
	Point2D(double _x = 0, double _y = 0);
	double getX() const;
	double getY() const;
};

