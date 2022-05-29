#include "Figure.h"

Figure::Figure(double x, double y, double strokeWidth,const std::string& _stroke) : points(x,y),
strokeWidth(strokeWidth), stroke(_stroke) { }
