#include <iostream>
#include "lib.h"

void read(int*& a, int& n) {
	if (a != nullptr) delete[] a;
	printf("Enter a size if array(>0):\n");
	std::cin >> n;
	a = new int[n];
	printf("Enter %d elements:\n", n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
}

int sumArray(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

void printArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}
}

int* randomArray(int n, int start, int end) {
	std::srand(time(nullptr));
	int* a = new int[n];
	int offset = end - start;
	for (size_t i = 0; i < n; i++) {
		a[i] = rand() % offset;
	}
	return a;
}

int sumRecursion(const int* arr, int n) {
	if (n > 0)
		return arr[0] + sumRecursion(arr + 1, n - 1);
	return 0;
}

int countPropertyRecurcion(const int* arr, int n, bool (*pred)(int)) {
	if (n > 0)
		return pred(arr[0]) ? 
		1 + countPropertyRecurcion(arr + 1, n - 1, pred) :
		countPropertyRecurcion(arr + 1, n - 1, pred);
	return 0;
}

bool isPositive(int number) {
	return number > 0;
}

bool isEven(int number) {
	return !(number & 1);
}

int maxInSegmentRecursion(const int* start, const int* end) {
	if (start + 1 == end) return *start;
	return std::max(*start, maxInSegmentRecursion(start + 1, end));
}

bool arrWithoutZeros(const int* arr, int length) {
	if (length == 0) return arr[0] != 0;
	return (arr[0] != 0 && arrWithoutZeros(arr + 1, length - 1));
}

double ArithmeticMean(const int* arr, int length) {
	
	int i = 0;
	double firstMean = 0;
	int firstCount = 0;
	while (*(arr + i) != 0 && i != length) {
		firstMean += *(arr + i);
		firstCount++;
		i++;
	}
	if (i == length) return 0;
	firstMean /= firstCount;
	while (*(arr + i) == 0) {
		i++;
	}

	double secondMean = 0;
	int secondCount = 0;
	while (*(arr + i) != 0 && i != length) {
		secondMean += *(arr + i);
		secondCount++;
		i++;
	}
	secondMean /= secondCount;
	return firstMean / secondMean;
}
