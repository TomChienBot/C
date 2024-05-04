#include <iostream>

void printVal(double d)
{
    d++;
    std::cout << d << '\n';
}

void printRef(int d)
{
    std::cout << d << '\n';
}

int main()
{
    printVal(4); // 5 converted to temporary double, copied to parameter d
    printRef(5); // 5 converted to temporary double, bound to parameter d

    return 0;
}