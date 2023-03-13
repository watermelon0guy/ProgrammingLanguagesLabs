#include <iostream>
#include "point.h"

Point add1(Point a, Point b) {
	return Point(a.getX() + b.getX(), a.getY() + b.getY());
}

Point add2(const Point& a, const Point& b) {
	return Point(a.getX() + b.getX(), a.getY() + b.getY());
}
