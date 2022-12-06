#include <iostream>
#include "lib.h"

int main()
{
    string str = "Hello World!";
    InsertSubStr(str, "zZz", 'l');
    std::cout << str;
}
