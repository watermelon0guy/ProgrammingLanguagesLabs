#include "lib.h"

int main()
{
    printf("Min Abs in text1.txt: %f\n", MinAbs("text1.txt"));
    MinMaxEachStr("text2.txt"); // смотреть файл
    pair<point, point> p = FurthestPoints("text3.txt");
    printf("Furthest point from text3.txt: %f %f %f %f\n", p.first.x, p.first.y, p.second.x, p.second.y);
    PrintPeople("text4.txt");
    return 0;
}
