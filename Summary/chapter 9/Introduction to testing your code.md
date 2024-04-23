[Introduction to testing your code](https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/)

1. Test your programs in small pieces
Việc kiểm tra từng đoạn code nhỏ một cách riêng lẻ để đảm bảo rằng "unit of code" là chính xác được gọi là kiểm tra đơn vị

Mỗi bài kiểm tra đơn vị được thiết kế đảm bảo rằng hành vi cụ thể của đoạn code là chính xác 
Ví dụ:
Khi bạn mua và kiểm tra từng bộ phân riêng lẻ của chiếc xe trước khi lặp đặt. Một khi các bộ phận chúng minh được nó có thể hoạt động, lặp đặt nó vào lại chiếc xe và kiểm tra toàn bộ lại để đảm bảo nó có thể hoạt động.

2. Informal testing

1 cách nữa để có thể test code là thực hiện informal testing(kiểm tra ko chính thức). Sau khi viết 1 đoạn code(1 hàm, 1 class, ..) có thể viết 1 vài dòng code để kiểm tra đoạn code b vừa viết và xóa đoạn test sau khi kiểm tra xong.
Ví dụ:
// We want to test the following function
bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    // So here's our temporary tests to validate it works
    std::cout << isLowerVowel('a') << '\n'; // temporary test code, should produce 1
    std::cout << isLowerVowel('q') << '\n'; // temporary test code, should produce 0

    return 0;
}
Nếu kết quả đoạn code trên trả về 1, 0 thì đoạn code trên đã được test thành công.

Automating your test functions:
1 vấn đề của đoạn mã test trên là nó phụ thuộc vào người dùng một cách thủ công.

Chúng ta có thể làm tốt hơn bằng việc viết 1 đoạn mã chứa cả đoạn test và giải thích kết quả: 
thêm hàm:
int testVowel() ?
{
    if (!isLowerVowel('a')) return 1;
    if (isLowerVowel('q')) return 2;

    return 0;//Nếu cả hai điều kiện trên đều không đúng, hàm testVowel sẽ trả về 0.
}
Thềm hàm testVowel() nếu giá trị trả về 0 thì test passed.

3.Unit testing frameworks:

Bởi vì việc viết các hàm để thực hiện các chức năng khác rất phổ biến và hữu ích nên có toàn bộ khung (được gọi là khung kiểm thử đơn vị) được thiết kế để giúp đơn giản hóa quá trình viết, duy trì và thực hiện kiểm thử đơn vị. Có thể sử dụng phần mềm của bên thứ 3.

4. Integration testing:

Khi mỗi đơn vị của bạn đã được kiểm tra riêng biệt, chúng có thể được tích hợp vào chương trình của bạn và kiểm tra lại để đảm bảo chúng được tích hợp đúng cách. Đây được gọi là thử nghiệm tích hợp.