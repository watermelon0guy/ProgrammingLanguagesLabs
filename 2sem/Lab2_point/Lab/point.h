#pragma once
#include <iostream>


class Point {
private:
    double x, y;

public:
    Point() { x = 0; y = 0; }
    Point(double x, double y) {
        this->x = x;
        this->y = y;
        std::cout << "Point created - (" << this->x << "," << this->y << ")" << std::endl;
    }

    Point(const Point& other) {
        x = other.getX();
        y = other.getY();
    }

    void print() { std::cout << "X = " << x << "; " << "Y = " << y << std::endl; }

    void add(const Point& p) {
        this->x += p.x;
        this->y += p.y;
    }
    void setPoint(double x, double y) {
        this->x = x;
        this->y = y;
    }

	~Point(){
		std::cout << "Destruct point: " << x << "; " << y <<"\n";
	}

    double getX() const { return this->x; }
    double getY() const { return this->y; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    void shiftX(double dx) { x += dx; }
    void shiftY(double dy) { y += dy; }

    bool isEqual(const Point& p) { return (abs(p.x - x) < 0.0000001 && abs(p.y - y) < 0.0000001); }

    double distanceTo(const Point& p) { return sqrt((x - p.getX()) * (x - p.getX()) + ((y - p.getY()) * (y - p.getY()))); }
};

Point add1(Point a,  Point b);
Point add2(const Point& a, const Point& b);


