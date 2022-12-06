#pragma once

void read(int*& a, int& n);

int sumArray(int* arr, int size);

void printArr(int* arr, int size);

int* randomArray(int n, int start = 0, int end = 10);

int sumRecursion(const int* arr, int n);

int countPropertyRecurcion(const int* arr, int n, bool(*pred)(int));

bool isPositive(int number);

bool isEven(int number);

int maxInSegmentRecursion(const int* start, const int* end);

bool arrWithoutZeros(const int* arr, int length);

double ArithmeticMean(const int* arr, int length);
