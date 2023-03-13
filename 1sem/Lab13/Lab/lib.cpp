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
	if (fin.eof()) throw 1;
	double max = 0, min = 0;
	int num = 1;
	string s;
	size_t dotPos = name.rfind('.');
	ofstream fout(name.insert(dotPos, "_output"));
	if (fin.eof()) fout << num << ") Max = " << temp << ", Min = " << temp << "\n";

	while (!fin.eof()) {
		while (fin.peek() != '\n' && !fin.eof()) {
			fin >> temp;
			if (!min) min = temp; 
			if (temp > max) max = temp;
			if (temp < min) min = temp;
		}
		while (fin.peek() == '\n')
			fin.ignore();
		fout << num << ") Max = " << max << ", Min = " << min << "\n";
		temp = 0, min = 0, max = 0;
		num++;
	}
	fin.close();
	fout.close();
}

double Distance(point p1, point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

//В текстовом файле в первой строке записано количество точек на плоскости, далее в
//каждой строке - координаты очередной точки.Найти две точки, наиболее удаленные друг
//от друга(любую пару, если таких несколько).
pair<point, point> FurthestPoints(string name) {
	ifstream fin(name);
	if (!fin.is_open()) throw 0;
	if (fin.eof()) throw 1;
	int amount = 0;
	fin >> amount;
	point* arrOfPoints = new point[amount];
	point p;

	for (size_t i = 0; i < amount; i++) {
		fin >> p.x >> p.y;
		arrOfPoints[i] = p;
	}
	pair <point, point> furthestPair;
	double maxDistance = -1.;
	
	for (int i = 0; i < amount; i++)
		for (int j = i; j < amount; j++) {
			double curDistance = Distance(arrOfPoints[i], arrOfPoints[j]);
			if (curDistance > maxDistance) {
				maxDistance = curDistance;
				furthestPair.first = arrOfPoints[i];
				furthestPair.second = arrOfPoints[j];
			}
		}
	delete[] arrOfPoints;
	fin.close();
	return furthestPair;
}

void PrintPeople(string name) {
	ifstream fin(name);
	if (!fin.is_open()) throw 0;
	if (fin.eof()) throw 1;
	int amount = 0;
	fin >> amount;
	person* arrOfPeople = new person[amount];
	person p;
	string fam, fname, patronymic;
	size_t dotPos = name.rfind('.');
	ofstream fout(name.insert(dotPos, "_output"));
	for (size_t i = 0; i < amount; i++) {
		fin >> fam >> fname >> patronymic;
		fam += fname + patronymic;
		fin >> p.birthday.day >> p.birthday.mounth >> p.birthday.year;
		fin >> p.gender;
		strcpy_s(p.fullname, fam.c_str());
		arrOfPeople[i] = p;
		fout << "|" << setw(15) << p.fullname << "|" << setw(3) << p.birthday.day << setw(3) << p.birthday.mounth << setw(5) << p.birthday.year << "|" << setw(2) << p.gender << "|" << endl;
	}
	delete[] arrOfPeople;
	fin.close();
	fout.close();
}