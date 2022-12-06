#include <iostream>
#include "lib.h"

int main() {
    const char* a1 = "";
    std::cout << (!a1) << std::endl;
    const char* a2 = nullptr;
    std::cout << (!a2) << std::endl;
    return 0;
}
