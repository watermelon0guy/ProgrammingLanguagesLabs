#include <iostream>
#include "lib.h"
#include "string"
#include <cmath>
//2, 3 в меню
double hyperbola(double x) {
	if (x)
		return 1 / x;
	throw 0;
}

double doubleHyperbola(double x) {
    if (x)
        return pow(x, 2) + 1/pow(x, 2);
    throw 0;
}

void table(double a, double b, int n, func f) {
    double h = (b - a) / (n - 1.0);
    double x, result;
    std::string hLine(14, '_');
    printf("|  x  | f(x) |\n"); // x - 5, f - 6
    printf("______________\n");
    for (int i = 0; i < n; i++)
    {
        x = a + h * i;
        try
        {
            result = f(x);
            printf("|%5.1f|%6.1f|\n", x, result);
            printf("______________\n");
        }
        catch (int)
        {
            printf("Error");
        }
    }
}

int reverse(int n) { // код не мой, но как же это красиво
    return ((n <= 9))
               ? n
               : reverse(n / 10)
                     + ((n % 10)
                        * (pow(10,
                               (floor(log10(
                                   abs(n)))))));
}

int nodRecursion(int a, int b) {
    a = abs(a), b = abs(b);
    if (b == 0) return a;
    return nodRecursion(b, a % b);
}
int nod(int a, int b) {
    a = abs(a); b = abs(b);
    while ((a > 0) and (b > 0))
        a > b ? a %= b : b %= a;
    return a + b;
}

double sqr(double k, double n) {
    double sum = k;
    for (int i = 1; i < n; i++)
        sum *= k;
    return sum;
}

bool odd(int x) {
    return x & 1;
}

double powRecusrsion(double k, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / powRecusrsion(k, -n);
    if (odd(n)) return k * powRecusrsion(k, n - 1);
    return sqr(powRecusrsion(k, n / 2), 2);
}

void firstWrapper() {
    double a{}, b{};
    int n{};
    printf("Enter [a,b] and step for y = 1/x (3 values):\n");
    std::cin >> a >> b >> n;
    table(a, b, n, hyperbola);
}

void secondWrapper() {
    int a = 0, b = 0, n = 0;
    printf("Enter [a,b] and step for y = (x^2) + 1/(x^2) (3 values):\n");
    std::cin >> a >> b >> n;
    table(a, b, n, doubleHyperbola);
}

void thirdWrapper() {
    int n;
    printf("Enter a number:\n");
    std::cin >> n;
    printf("Reversed number: %d\n", reverse(n));
}

void fourthWrapper() {

}

void menu() {
    bool cond = true;
    const int task_amount = 4;
    int choice;
    while (cond) {
        printf("Choose a function(1 - %i, 0 - exit):\n", task_amount);
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
        case 0:
            cond = false;
            break;
        default:
            printf("There is no such function. Use numbers 1 - %i", task_amount);
        }
    }
}
