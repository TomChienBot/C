#include <iostream>

int main(){
    int x { 10 };
    int y { 4 };
    double d{(double)x/y} ; // does integer division, initializes d with value 2.0
    double z = x/y;
    std::cout << d << "\t" << z;
}