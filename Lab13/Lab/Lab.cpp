#include "lib.h"

int main()
{
    pair<point, point> a = FurthestPoints("text2.txt");
    printf("%f %f %f %f", a.first.x, a.first.y, a.second.x, a.second.y);
    return 0;
}
