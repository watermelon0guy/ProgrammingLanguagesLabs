#include "lib.h"

double MinAbs(string name) {
	ifstream fin(name);
	if (!fin.is_open()) throw 0;
	double minAbs = 0; double minAbsOrg = 0;
	if (!(fin >> minAbsOrg)) throw 1;
	minAbs = minAbsOrg;
	double temp = 0;
	while (fin >> temp) {
		if (abs(temp) < minAbs) {
			minAbsOrg = temp;
			minAbs = abs(temp);
		}
	}
	return minAbsOrg;
}

void MinMaxEachStr(string name) {
	ifstream fin(name);
	double temp = 0;
	if (!fin.is_open()) throw 0;
	if (!(fin >> temp)) throw 1;
	double max = 0, min = 0;
	int num = 1;
	string s;
	ofstream fout(name + "_output");
	if (fin.eof()) fout << num << ") Max = " << temp << ", Min = " << temp << "\n";

	while (!fin.eof()) {
		while (fin.peek() != '\n' && !fin.eof()) {
			fin >> temp;
			if (temp > max) max = temp;
			if (temp < min) min = temp;
		}
		//TODO()
	}
}


//В текстовом файле в первой строке записано количество точек на плоскости, далее в
//каждой строке - координаты очередной точки.Найти две точки, наиболее удаленные друг
//от друга(любую пару, если таких несколько).
pair<point, point> FurthestPoints(string name) {
	ifstream fin(name);
	if (!fin.is_open()) throw 0;
	if (fin.peek() == char_traits<char>::eof()) throw 1;
	pair<point, point> furthestPair = {point(0, 0), point(0,0)};
	return furthestPair;
}