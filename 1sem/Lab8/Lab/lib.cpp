#include <iostream>
#include "lib.h"

void PrintMatrix(matrix matr, int rows, int cols) {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			printf("%4d ", matr[i][j]);
		}
		printf("\n");
	}
}

int CountRowsWithZeros(matrix matr, int rows, int cols) {
	int counter = 0;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (matr[i][j] == 0) {
				counter++;
				break;
			}
		}
	}
	return counter;
}

bool IsSymmetric(matrix matr, int n) {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = i + 1; j < n; j++) {
			if (matr[i][j] != matr[j][i]) return false;
		}
	}
	return true;
}

void TransposeMatrix(matrix &matr, int &rows, int &cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = i + 1; j < cols; ++j) {
			std::swap(matr[i][j], matr[j][i]);
		}
	}

	std::swap(rows, cols);
}

// Строка для удаления считается с 0
void DeleteRow(matrix &matr, int& rows, int cols, int rowForDeletion) {
	if ((rowForDeletion < 0) || (rowForDeletion >= rows))
		return;
	for (int i = rowForDeletion; i < rows - 1; ++i)
		for (int j = 0; j < cols; ++j)
			matr[i][j] = matr[i + 1][j];
	rows--;
}

void AddRow(matrix& matr, int& rows, int cols, int rowForAddition, int *arr) {
	if ((rows + 1 > MAX_ROWS) || (rowForAddition < 0) || (rowForAddition > rows)) return;
	for (int i = rows; i >= rowForAddition; i--)
		for (int j = 0; j < cols; ++j)
			matr[i][j] = matr[i - 1][j];
	
	// Если массив меньше зажанной строчки, то это будут проблемы пользователя.
	// Можно вместе с массивом передавать и его длину, но сам смысл подразумевает, что она будет длиной со строку матрицы
	for (int j = 0; j < cols; ++j)
		matr[rowForAddition][j] = arr[j];
	rows++;
}


void DeleteCol(matrix& matr, int rows, int& cols, int colForDeletion) {
	if ((colForDeletion < 0) || (colForDeletion >= cols))
		return;
	for (int i = colForDeletion; i < cols - 1; ++i)
		for (int j = 0; j < rows; ++j)
			matr[j][i] = matr[j][i + 1];
	cols--;
}

void DeleteRowCol(matrix& matr, int& rows, int& cols, int rowForDeletion, int colForDeletion) {
	DeleteRow(matr, rows, cols, rowForDeletion);
	DeleteCol(matr, rows, cols, colForDeletion);
}