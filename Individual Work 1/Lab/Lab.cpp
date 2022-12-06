#include <iostream>
#include "lib1.h"

int main() {
    int counterLastDigitNotRepeat = 0;

    int num = 0;
    int maxSum = 0;
    int currSum;

    printf("Enter N(number of elements):\n");
    int n;
    std::cin >> n;
    printf("Enter a sequence of integers:\n");
    int tempNum;
    for (size_t i = 0; i < n; i++) {
        std::cin >> tempNum;
        if (IsLastDigitNotRepeat(tempNum)) {
            counterLastDigitNotRepeat++;
        }

        if (tempNum % 2 == 0) continue;
        currSum = SumOfDigits(tempNum);
        if (currSum > maxSum) {
            maxSum = currSum;
            num = tempNum;
        }
    }
    printf("Amount of numbers where last digit not repeat: %d\n", counterLastDigitNotRepeat);
    printf("Max sum of digits of odd numbers: %d\n", num);
}

