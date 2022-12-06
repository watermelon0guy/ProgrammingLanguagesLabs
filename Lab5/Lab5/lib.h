#pragma once

void printArray(int* arr, int size);

int sumArray(int* arr, int size);

void productOfTwoArrays(int* arr1, int* arr2, int* arr3, int size);

void insertionSort(int* arr, int size);

bool anyZero(int* arr, int size);

bool anyDuplNeighbours(int* arr, int size);

bool anyPredicate(int* arr, int size, bool(*pred)(int));

bool anyPredicate(int* arr, int size, bool(*pred)(int, int));

bool isPositive(int number);
bool isEven(int number);
bool isContains5(int number);

bool sameSigns(int number1, int number2);
bool differentSigns(int number1, int number2);
bool nonDecreasingPair(int number1, int number2);