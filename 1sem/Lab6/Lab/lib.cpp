#include "lib.h"
// сменил стиль именования всего, потому что прочитал гугловсий c++ style
void Read(int*& a, int& n) {
	printf("Enter a size if array(>0):\n");
	std::cin >> n;
	a = new int[n];
	printf("Enter %d elements:\n", n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
}

void PrintArray(int* arr, int size) {
	printf("Elements: ");
	for (size_t i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int* RandomArrayInit(int n, int start, int end) {
	std::srand(time(nullptr));
	int* a = new int[n];
	int offset = end - start;
	for (size_t i = 0; i < n; i++) {
		a[i] = start + rand() % offset;
	}
	return a;
}

void InsertMid(int*& a, int& n, int el) {
	int* newArr = new int[n + 1];
	int offset = 0;
	for (size_t i = 0; i < n + 1; i++) {
		newArr[i] = a[i - offset];
		if (i == n / 2 + n % 2) {
			newArr[i] = el;
			offset++;
		}
	}
	n++;
	delete[] a;
	a = newArr;
}

// не очень понял момент с удалением неиспользуемой памяти
// наверное речь шла о дублировании массива
void DeleteDuplicate(int* array, int& size) { 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i != j) {
				if (array[i] == array[j]) {
					std::swap(array[size - 1], array[j]);
					size-=1;
				}
			}
		}
	}
}

bool AnyPredicate(int* arr, int size, bool (*pred)(int)) {
	for (int i = 0; i < size; i++) {
		if (!pred(arr[i])) {
			return false;
		}
	}
	return true;
}

bool IsPositive(int number) {
	return number >= 0;
}

bool IsEven(int number) {
	return !(number & 1);
}

int BinSearchArray(int* a, int size, int val) {
	int left = 0, right = size - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (a[mid] < val) {
			left = mid + 1;
		}
		else if (a[mid] > val) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -(left + 1);
}

void InsertionSort(int* arr, int size) {
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

int DoublePredicatePosition(int* arr, int size, bool (*pred)(int, int)) {
	for (int i = 0; i < size - 1; i++) {
		if (pred(arr[i], arr[i + 1])) {
			return i;
		}
	}
	return -1;
}

bool DecreasingPair(int number1, int number2) {
	return number1 <= number2;
}

bool IsEqual(int number1, int number2) {
	return number1 == number2;
}