#include "lib.h"

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
	for (int i = 0; i < rows; ++i) {
		delete[] m[i];
		m[i] = nullptr;
	}
	delete[] m;
	m = nullptr;
}

double MainSecondarySumRatio(double**& m, int rows, int cols) {
	double sumMain = 0, sumSecondary = 0;
	for (size_t row = 0; row < rows; row++) {
		if (row != cols) sumMain += m[row][row];
		if (cols - row > 0) sumSecondary += m[row][cols - 1 - row];
	}
	if (sumSecondary == 0) throw std::runtime_error("Math error: Attempted to divide by Zero\n");
	return sumMain / sumSecondary;
}

void SmallestPosElInRow(double**& m, int rows, int& cols) {
	cols++;
	double** temp_matr = nullptr;
	temp_matr = new double* [rows];
	for (size_t row = 0; row < rows; ++row) {
		double smallestInRow = 0;
		temp_matr[row] = new double[cols];
		
		for (size_t col = 0; col < cols; col++) {
			if (((smallestInRow > m[row][col] && m[row][col] > 0) ||
				(smallestInRow == 0 && m[row][col] > 0)) && col != cols - 1) {
				smallestInRow = m[row][col];
			}

			if (col != cols - 1) {
				temp_matr[row][col] = m[row][col];
			}
			else {
				temp_matr[row][col] = smallestInRow;
			}
		}
	}
	DeleteMatrix(m, rows);
	m = temp_matr;
}

// проверить если матрица из одной строчки
void DeleteRow(double**& m, int& rows, int rowDelete) {
	rows--;
	double** temp_matr = nullptr;
	temp_matr = new double* [rows];
	int offset = 0;
	for (size_t row = 0; row < rows; row++) {
		if (row == rowDelete) {
			offset = 1;
			delete[] m[rowDelete];
		}
		temp_matr[row] = m[row + offset];
	}
	delete[] m;
	m = nullptr;
	m = temp_matr;
}

void DeleteCol(double**& m, int rows, int& cols, int colDelete) {
	cols--;
	double** temp_matr = nullptr;
	temp_matr = new double* [rows];
	int offset = 0;
	for (size_t row = 0; row < rows; row++) {
		offset = 0;
		temp_matr[row] = new double[cols - 1];
		for (size_t col = 0; col < cols; col++) {
			if (col == colDelete) {
				offset = 1;
			}
			temp_matr[row][col] = m[row][col + offset];
		}
	}
	DeleteMatrix(m, rows);
	m = temp_matr;

}
