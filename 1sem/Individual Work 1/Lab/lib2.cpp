#include "lib2.h"

double IntegralExponentialFunction(double x, double eps) {
	double part1 = 0.5772157 + log(x);
	double k = 1;
	double powX = x;
	double tempFactorial = 1;
	double part2 = -powX;
	double tempSum = part2;
	int sign = -1;
	while (fabs(tempSum) > eps)
	{
		k++;
		powX *= x;
		tempFactorial *= k;
		sign *= -1;
		tempSum = powX / (k * tempFactorial) * sign;
		part2 += tempSum;
	}

	return (part1 + part2) * -1;
}
