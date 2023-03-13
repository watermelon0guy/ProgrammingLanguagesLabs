#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

double MinAbs(string name);

void MinMaxEachStr(string name);

struct point {
	double x, y;
	point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	point() {}
};

pair<point, point> FurthestPoints(string name);

void PrintPeople(string name);

struct date {
	size_t day, mounth;
	int year;
};

struct person {
	char fullname[128];
	date birthday;
	char gender;
	/*person(char* name, size_t day, size_t mounth, int year, char g) {
		strcpy(fullname)
	}*/
};
