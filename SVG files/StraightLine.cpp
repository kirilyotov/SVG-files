#include "StraightLine.h"

StraightLine::StraightLine(double x, double y, double x2, double y2, double strokeWidth, const std::string& stroke) :
	Figure(x, y, strokeWidth, stroke), secPoint(x2, y2) { }

std::ostream& operator<<(std::ostream& out, const StraightLine& line)
{
	out << "line " << line.points.getX() << " " << line.points.getY() << " " << line.secPoint.getX() << " " << line.secPoint.getY()
		<< " " << line.strokeWidth << " " << line.stroke;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, StraightLine& line)
{
	return in;
}

std::ofstream& operator<<(std::ofstream& out, StraightLine& line)
{
	out << "<circle x1=\"" << line.points.getX() << "\" y1=\"" << line.secPoint.getY() << "\" x2=\"" << line.secPoint.getY()
		<< "\" y2=\"" << line.secPoint.getY() << " stroke=\"" << line.stroke << "\"  stroke-width=\""
		<< line.stroke << "\" />";

	return out;
}
