#pragma once
#include <iostream>
#include <stdexcept>
#include <limits>

void ReadNew(double**& m, int& rows, int& cols);

void PrintMatrix(double** matr, int rows, int cols);

void DeleteMatrix(double**& m, int rows);

double MainSecondarySumRatio(double**& m, int rows, int cols);

void SmallestPosElInRow(double**& m, int rows, int& cols);

void DeleteRow(double**& m, int& rows, int rowDelete);

void DeleteCol(double**& m, int rows, int& cols, int colDelete);
