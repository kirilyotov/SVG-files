#pragma once
//Could be struct
class Point2D
{
protected:
	//points
	double x;
	double y;
public:
	//constructor with parameters
	Point2D(double _x = 0, double _y = 0);
	//Getters for x & y
	double getX() const;
	double getY() const;
};

