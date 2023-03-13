#include <iostream>

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int n = 2;
    std::cout << a[n] << " " << *(a + n) << std::endl;
    std::cout << *(n + a) << " " << n[a] << std::endl;
}
