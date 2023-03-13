#include <iostream>
#include "lib.h"

int main()
{
    int size;
    printf("Size of array: ");
    std::cin >> size;
    int* a = RandomArrayInit(size, -5, 5);
    InsertionSort(a, size);
    PrintArray(a, size);
    printf("Positive check(1-true, 0-false): %d\n", AnyPredicate(a, size, IsPositive));
    printf("Even check(1-true, 0-false): %d\n", AnyPredicate(a, size, IsEven));
    printf("Equal neighbours check(-1 - not found): %d\n", DoublePredicatePosition(a, size, IsEqual));
    printf("Decreasing pair check(-1 - not found): %d\n", DoublePredicatePosition(a, size, DecreasingPair));
    printf("Element for bin search: ");
    int element;
    std::cin >> element;
    printf("Index of the desired element: %d\n", BinSearchArray(a, size, element));

    delete[] a;
}