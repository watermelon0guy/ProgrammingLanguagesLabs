#include <iostream>
#include "lib.h"

int main()
{
    int size;
    size = 5;
    int* a = new int[size]{1, 2, 3, 4, 5};
    printArr(a, size);
    printf("%d", sumRecursion(a, size));

    delete[] a;
}