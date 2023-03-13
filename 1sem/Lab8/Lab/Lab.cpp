#include <iostream>
#include "lib.h"

int main()
{
    int matr[MAX_ROWS][MAX_COLS] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int rows = 3;
    int cols = 3;
    int arr[3] = { 1, 2, 3 };
    DeleteCol(matr, rows, cols, 1);
    PrintMatrix(matr, rows, cols);
}
