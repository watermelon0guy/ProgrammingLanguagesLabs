#pragma once
#include <iostream>

void Read(int*& a, int& n);

void PrintArray(int* arr, int size);

int* RandomArrayInit(int n, int start = 0, int end = 10);

void InsertMid(int*& a, int& n, int el);

void DeleteDuplicate(int* array, int& size);

bool AnyPredicate(int* arr, int size, bool(*pred)(int));

bool IsPositive(int number);

bool IsEven(int number);

int BinSearchArray(int* a, int size, int val);

void InsertionSort(int* arr, int size);

int DoublePredicatePosition(int* arr, int size, bool(*pred)(int, int));

bool DecreasingPair(int number1, int number2);

bool IsEqual(int number1, int number2);
