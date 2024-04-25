#include<iostream>

int main(){
    double d { 3.5 };

    // static_cast<int> converts double to int, initializes i with int result

    int i {static_cast<int>(d)};

    std::cout << i;
}