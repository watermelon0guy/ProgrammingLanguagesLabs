#include "lib3.h"

double func(double x, int n) {
	if (n == 0) return 1;
	return func(x, n - 1) * x / n;
}
