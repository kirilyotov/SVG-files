#include "Rectangle.h"

Rectangle::Rectangle(double x, double y, double _width, double _height,
	const std::string& _fill, double stroke, const std::string& strokeWidth) : Figure(x, y, stroke, strokeWidth) , 
	width(_width), height(_height), fill(_fill) { }

std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle)
{
	out << "circle " << rectangle.points.getX() << " " << rectangle.points.getX() << " " << rectangle.width << " " << rectangle.height << " " << rectangle.fill;

	if (rectangle.strokeWidth > 0 || rectangle.stroke != "none")
		out << " " << rectangle.strokeWidth << " " << rectangle.stroke;

	return out;
}

std::ofstream& operator<<(std::ofstream& out, Rectangle& rectangle)
{
	out << "<rect x=\"" << rectangle.points.getX() << "\" y=\"" << rectangle.points.getY() << "\" width=\"" << rectangle.width
		<< "\" height=\"" << rectangle.height << "\" r=\" fill=\"" << rectangle.fill;

	if (rectangle.strokeWidth > 0 || rectangle.stroke != "none")
		out << " stroke=\"" << rectangle.stroke << "\"  stroke-width=\"" << rectangle.stroke;

	out << "\" />";

	return out;
}
