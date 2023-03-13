#define _USE_MATH_DEFINES
#include <iostream>
#include "lib.h"

int checkBit(int num, int i) {
    return num & (1 << (i - 1));
}

void setBit(int& num, int i, bool value) {
    int mask = 1 << (i - 1);
    if (checkBit(num, i) != value)
        if (value == 1)
            num ^= mask;
        else
            num &= ~mask;
}

double expTeylor(double x, double eps) {
    double a = 1, s = 0;
    for (int n = 1; abs(a) > eps; n++) {
        s += a;
        a *= x / n;
    }
    return s;
}

double sinTeylor(double x, double eps) {
    while (abs(x) > 2 * M_PI) {
        x = x > 0 ? x - M_PI : x + M_PI;
    }
    double sum = x, elem = x;
    int i = 0;
    while (abs(elem) >= eps) {
        i++;
        elem *= -x * x / (2. * i) / (2. * i + 1);
        sum += elem;
    }
    return sum;
}
