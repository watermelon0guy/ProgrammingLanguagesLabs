#include "lib.h"

double sigma(int n) {
	double sum = 0;
	int factorial = 1;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		sum += pow(-1, i) / factorial;
	}
	return sum;
}
