[Introduction to compound data types](https://www.learncpp.com/cpp-tutorial/introduction-to-compound-data-types/) (Giới thiệu về các kiểu dữ liệu phức hợp)

Cho đến nay, chúng ta đã sử dụng nhiều các kiểu cơ bản này trong các chương trình của mình, đặc biệt là kiểu dữ liệu int. Và mặc dù những loại cơ bản này cực kỳ hữu ích cho những mục đích sử dụng đơn giản nhưng chúng không đáp ứng đầy đủ các nhu cầu của chúng ta khi chúng ta bắt đầu làm những việc phức tạp hơn.

hãy tưởng tượng bạn đang viết một chương trình toán để nhân hai phân số. Bạn sẽ biểu diễn một phân số trong chương trình của mình như thế nào? Bạn có thể sử dụng một cặp số nguyên (một cho tử số, một cho mẫu số), như sau:

#include <iostream>

int main()
{
    // Our first fraction
    int num1 {};
    int den1 {};

    // Our second fraction
    int num2 {};
    int den2 {};

    // Used to eat (remove) the slash between the numerator and denominator
    char ignore {};

    std::cout << "Enter a fraction: ";
    std::cin >> num1 >> ignore >> den1;

    std::cout << "Enter a fraction: ";
    std::cin >> num2 >> ignore >> den2;

    std::cout << "The two fractions multiplied: "
        << num1 * num2 << '/' << den1 * den2 << '\n';

    return 0;
}

1. Compound data types
C++ hỗ trợ tập hợp kiểu dữ liệu thứ hai được gọi là kiểu dữ liệu phức hợp. Kiểu dữ liệu phức hợp (đôi khi còn được gọi là kiểu dữ liệu tổng hợp) là các kiểu dữ liệu có thể được xây dựng từ các kiểu dữ liệu cơ bản (hoặc các kiểu dữ liệu phức hợp khác). Mỗi loại dữ liệu phức hợp cũng có các thuộc tính riêng.

C++ supports the following compound types:

Functions

Arrays

Pointer types:

    * Pointer to object

    * Pointer to function
Pointer to member types:

    * Pointer to data member

    * Pointer to member function

Reference types:

    L-value references

    R-value references

Enumerated types:

Unscoped enumerations

Scoped enumerations

Class types:

    Structs

    Classes

    Unions

