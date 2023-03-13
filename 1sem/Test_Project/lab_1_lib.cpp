//
// Created by watermelon on 07.09.2022.
//

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "lab_1_lib.h"

void menu(int cond) {

}


int factorial(int num) {
    int factorial = 1;
    for (int i = 1; i < num + 1; ++i) {
        factorial *= i;
    }
    return factorial;
}



int amountDigits(int num) {
    int amount=0;
    do {
        num /= 10;
        amount++;
    }
    while (num != 0);
    return amount;
}

int sumDigits(int num) {
    int x = abs(num);
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void swap(float &a, float &b) {
    float r = a;
    a = b;
    b = r;
}

void swap(int &a, int &b) {
    int r = a;
    a = b;
    b = r;
}

inline int maxFunc(int a, int b) {
    return a < b? b : a;
}

inline int maxFunc(int a, int b, int c) {
    int temp = a < b? b : a;
    return temp < c? c : temp;
}

inline float maxFunc(float a, float b) {
    return a < b? b : a;
}

inline float maxFunc(float a, float b, float c) {
    float temp = a < b? b : a;
    return temp < c? c : temp;
}

bool firstLastDigit(int num) {
    bool answer;
    int digit2;
    digit2 = num % 10;
    num = abs(num);
    while (num >= 10) {
        num /= 10;
    }
    return num == digit2;
}

int eraseFirstLastDigits(int num) {
    bool minus = num < 0;
    num = abs(num);
    num /= 10;
    int temp_num = num;
    int i = 0;
    while (temp_num >= 10) {
        temp_num /= 10;
        i++;
    }
    num -= temp_num * pow(10, i);
    if (minus) {
        num *= -1;
    }
    return num;
}

int swapFirstLastDigits(int num) {
    bool minus = num < 0;
    int digitsAmount = amountDigits(num);
    num = abs(num);
    int digit2 = num % 10;
    int digit1 = num / pow(10, digitsAmount - 1);
    num = eraseFirstLastDigits(num) * 10 + digit1 + pow(10, digitsAmount - 1) * digit2;
    if (minus) {
        num *= -1;
    }
    return num;
}

int everyOneBitCounter(int num) {
    int count = 0;
    for (; num; num >>= 1)
        count += num & 1;
    return count;
}

int everyZeroBitCounter(int num) {
    int count = 0;
    for (; num; num >>= 1)
        count += num & 0;
    return count;
}

int customPow(int num, int power) {
    int powered_num = num;
    for (int i = 1; i < power; ++i) {
        powered_num *= num;
    }
    return powered_num;
}

bool isEqualWeirdFunction(int n, int k) {
    int x = abs(n);
    int sum = 0;
    while (x != 0) {
        sum += (x % 10) * k;
        x /= 10;
    }
    return sum == n;
}

void firstWrapper() {
    std::cout << "Enter a factorial value:" << std::endl;
    int value;
    std::cin >> value;
    std::cout << factorial(value) << std::endl;
}

void secondWrapper() {
    std::cout << "Enter a value:" << std::endl;
    int value;
    std::cin >> value;
    std::cout << "Amount: " << amountDigits(value) << " Sum: " << sumDigits(value) << std::endl;
}

void thirdWrapper() {
    int a, b;
    float c, d;
    std::cout << "Enter two int values:" << std::endl;
    std::cin >> a; std::cin >> b;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    std::cout << "Enter two float values:" << std::endl;
    std::cin >> c; std::cin >> d;
    swap(c, d);
    std::cout << c << " " << d << std::endl;

}

void fourthWrapper() {
    int a, b, c;
    float d, e, f;
    std::cout << "Enter two int values:" << std::endl;
    std::cin >> a; std::cin >> b;
    std::cout << maxFunc(a, b) << std::endl;
    std::cout << "Enter three int values:" << std::endl;
    std::cin >> a; std::cin >> b; std::cin >> c;
    std::cout << maxFunc(a, b, c) << std::endl;

    std::cout << "Enter two float values:" << std::endl;
    std::cin >> d; std::cin >> e;
    std::cout << maxFunc(d, e) << std::endl;
    std::cout << "Enter three float values:" << std::endl;
    std::cin >> d; std::cin >> e; std::cin >> f;
    std::cout << maxFunc(d, e, f) << std::endl;
}

void fifthWrapper() {
    std::cout << "Enter an int value:" << std::endl;
    int num;
    std::cin >> num;
    if (firstLastDigit(num)) {
        std::cout << eraseFirstLastDigits(num) << std::endl;
    }
    else {
        std::cout << swapFirstLastDigits(num) << std::endl;
    }
}

void sixthWrapper() {
    std::cout << "Enter an int value:" << std::endl;
    int num;
    std::cin >> num;
    std::cout << "Zero bit:" << std::endl;
    std::cout << everyZeroBitCounter(num) << std::endl;
    std::cout << "One bit:" << std::endl;
    std::cout << everyOneBitCounter(num) << std::endl;
}

void seventhWrapper() {
    std::cout << "Enter number and power:" << std::endl;
    int n, k;
    std::cin >> n >> k;
    std::cout << "Power:" << std::endl;
    std::cout << customPow(n, k) << std::endl;
    std::cout << "Weird func:" << std::endl;
    std::cout << isEqualWeirdFunction(n, k) << std::endl;
}

void menu() {
    bool cond = true;
    int choice;
    while (cond) {
        std::cout << "Choose a function: " << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                firstWrapper();
                break;
            case 2:
                secondWrapper();
                break;
            case 3:
                thirdWrapper();
                break;
            case 4:
                fourthWrapper();
                break;
            case 5:
                fifthWrapper();
                break;
            case 6:
                sixthWrapper();
                break;
            case 7:
                seventhWrapper();
                break;
            case 0:
                cond = false;
                break;
            default:
                std::cout << "There is no such function. Use numbers 1-7" << std::endl;
        }
    }
}
