#include <iostream>
#include <cassert> // for assert()

int main(){

std::string message{};
std::cout << "Enter a message: ";
std::cin >> message;

assert(message == "abunai");


std::cout << "Next word";

return 0;
}