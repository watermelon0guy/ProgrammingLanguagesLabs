#include "lib.h"

void leftDig(int &numb, int cf)
{
    int amountOfDigits = amountDigits(numb);
    int temp = cf * pow(10, amountOfDigits) * (numb < 0 ? -1 : 1);
    numb += temp;
}

int amountDigits(int num) {
    int amount = 0;
    do {
        num /= 10;
        amount++;
    } while (num != 0);
    return amount;
}