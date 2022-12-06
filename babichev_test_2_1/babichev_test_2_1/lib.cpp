#include <iostream>
#include "lib.h"

//Дана матрица вещественных чисел в динамической памяти.
//Описать функцию для вычисления максимального количества ненулевых элементов в столбце матрицы.

int Func(double** matr, int rows, int cols) {
	int maxC = 0;
	int currentMax = 0;
	for (size_t col = 0; col < cols; col++) {
		for (size_t row = 0; row < rows; row++) {
			if (matr[row][col] == 0) currentMax++;
		}
		if (maxC < currentMax) maxC = currentMax;
		currentMax = 0;
	}
	return maxC;
}

void ReadNew(double**& m, int& rows, int& cols) {
	printf("Enter the number of rows and colums(two numbers):");
	std::cin >> rows >> cols;
	m = new double* [rows];

	for (size_t row = 0; row < rows; row++) {
		m[row] = new double[cols];
		printf("Enter %d row(%d numbers): ", row + 1, cols);
		for (size_t col = 0; col < cols; col++) {
			std::cin >> m[row][col];
		}
	}
	printf("Matrix initialized\n");
}

void PrintMatrix(double** matr, int rows, int cols) {
	printf("Matrix:\n");
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			printf("%4f ", matr[i][j]);
		}
		printf("\n");
	}
}

void DeleteMatrix(double**& m, int rows) {
	for (int i = 0; i < rows; ++i) delete[] m[i];
	delete[] m;
	m = nullptr;
}