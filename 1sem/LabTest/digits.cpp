//
// Created by watermelon on 14.09.2022.
//

#include "digits.h"

int digits(int n) {
    int k = 0;
    while (n > 10) {
        n /= 10;
    }
    return k;
}
