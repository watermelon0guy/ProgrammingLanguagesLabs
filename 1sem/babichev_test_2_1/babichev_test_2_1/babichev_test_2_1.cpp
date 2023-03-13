#include <iostream>
#include "lib.h"

int main()
{
    double** matr = nullptr;
    int rows, cols;
    ReadNew(matr, rows, cols);
    PrintMatrix(matr, rows, cols);
    std::cout << Func(matr, rows, cols);
    DeleteMatrix(matr, rows);
}
