#pragma once

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
typedef int matrix[MAX_ROWS][MAX_COLS];

void PrintMatrix(matrix matr, int rows, int cols);

int CountRowsWithZeros(matrix matr, int rows, int cols);

bool IsSymmetric(matrix matr, int n);

void TransposeMatrix(matrix &matr, int &rows, int &cols);

void DeleteRow(matrix &matr, int& rows, int cols, int rowForDeletion);

void AddRow(matrix& matr, int& rows, int cols, int rowForAddition, int* arr);

void DeleteCol(matrix& matr, int rows, int& cols, int colForDeletion);

void DeleteRowCol(matrix& matr, int& rows, int& cols, int rowForDeletion, int colForDeletion);
