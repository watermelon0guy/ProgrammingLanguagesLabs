#include "lib.h"

//Дан массив целых чисел.Удалить из массива все элементы, равные заданному значению.
//Массив расположен в динамической памяти.

void Func(int*& arr, int &n, int forDel) {
	int newN = n;
	
	for (size_t i = 0; i < n; i++) {
		if (arr[i] == forDel) newN--;
	}

	int* arrNew = new int[newN];
	int tempIndex = 0;
	for (size_t i = 0; i < n; i++) {
		if (arr[i] != forDel) {
			arrNew[tempIndex] = arr[i];
			tempIndex++;
		}
	}

	n = newN;
	delete[] arr;
	arr = arrNew;
}
