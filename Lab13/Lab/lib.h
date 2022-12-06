#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double MinAbs(string name);

struct point {
	double x, y;
	point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

pair<point, point> FurthestPoints(string name);