#include <iostream>
#include "lib.h"

void printArray(int* arr, int size) {
	std::cout << "Array: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int sumArray(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

void productOfTwoArrays(int* arr1, int* arr2, int* arr3, int size) {
	for (int i = 0; i < size; i++) {
		arr3[i] = arr1[i] * arr2[i];
	}
}

void insertionSort(int* arr, int size) {
	int temp, item;
	for (int i = 1; i < size; i++) {
		temp = arr[i];
		item = i - 1;
		while (item >= 0 && arr[item] > temp) {
			arr[item + 1] = arr[item];
			arr[item] = temp;
			item--;
		}
	}
}

bool anyZero(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) {
			return false;
		}
	}
	return true;
}

bool anyDuplNeighbours(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			return false;
		}
	}
	return true;
}

bool anyPredicate(int* arr, int size, bool(*pred)(int)) {
	for (int i = 0; i < size; i++) {
		if (!pred(arr[i])) {
			return false;
		}
	}
	return true;
}

bool anyPredicate(int* arr, int size, bool (*pred)(int, int)) {
	for (int i = 0; i < size - 1; i++) {
		if (!pred(arr[i], arr[i + 1])) {
			return false;
		}
	}
	return true;
}

bool isPositive(int number) {
	return number > 0;
}

bool isEven(int number) {
	return !(number & 1);
}

bool isContains5(int number) {
	while (number != 0) {
		int curr_digit = number % 10;
		if (curr_digit == 5) return true;
		number /= 10;
	}
	return false;
}
// не очень понял момент с "два элемента имеют разные / одинаковые знаки"
// поэтому сделал два предиката
bool sameSigns(int number1, int number2) {
	return ((number1 < 0) && (number2 < 0)) || ((number1 >= 0) && (number2 >= 0));
}

bool differentSigns(int number1, int number2) {
	return ((number1 < 0) && (number2 >= 0)) || ((number1 >= 0) && (number2 < 0));
}

bool nonDecreasingPair(int number1, int number2) {
	return number1 <= number2;
}

