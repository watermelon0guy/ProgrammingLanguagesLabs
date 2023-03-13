#include <iostream>
#include "lib.h"

int main()
{
    int number = 5;
    setBit(number, 2, 1);
    std::cout << number;
    setBit(number, 2, 0);
    std::cout << number;
}
