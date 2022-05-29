#include "Circle.h"

Circle::Circle(double cx, double cy, double _r,const std::string& _fill, double stroke ,const std::string& strokeWidth) :
	Figure(cx, cy, stroke, strokeWidth), r(_r), fill(_fill) { }



std::ostream& operator<<(std::ostream& out, const Circle& circle)
{
	out << "circle " << circle.points.getX() << " " << circle.points.getY() << " " << circle.r << " " << circle.fill;
	if (circle.strokeWidth > 0 || circle.stroke != "none")
		out << " " << circle.strokeWidth << " " << circle.stroke;
	return out;
}



std::ifstream& operator>>(std::ifstream& in, Circle& circle)
{
	return in;
}

std::ofstream& operator<<(std::ofstream& out, Circle& circle)
{
	out << "<circle cx=\"" << circle.points.getX() << "\" cy=\"" << circle.points.getY() << "\" r=\"" << circle.r
		<< "\" fill=\"" << circle.fill;

	if (circle.strokeWidth > 0 || circle.stroke != "none")
		out << " stroke=\"" << circle.stroke << "\"  stroke-width=\"" << circle.stroke;

	out << "\" />";

	return out;
}

