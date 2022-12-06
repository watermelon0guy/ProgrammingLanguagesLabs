#include <iostream>
#include "lib.h"

int main()
{
    double** matr = nullptr;
    int rows, cols;
    int col = 1;
    ReadNew(matr, rows, cols);
    PrintMatrix(matr, rows, cols);
    DeleteCol(matr, rows, cols, col);
    PrintMatrix(matr, rows, cols);
    DeleteMatrix(matr, rows);
}
