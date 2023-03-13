#include <iostream>
#include "lib.h"

int main()
{
    printf("Examples for N in [1,10]\n");
	for (int i = 1; i <= 10; i++)
	{
		std::cout << "Answer for " << i << ": " << sigma(i) << std::endl;
	}
	return 0;
}
