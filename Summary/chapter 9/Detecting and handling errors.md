[Detecting and handling errors](https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/#google_vignette)

Hầu hết các lỗi trong chương trình không xảy ra do vô tình sử dụng sai các tính năng ngôn ngữ. Đúng hơn, hầu hết các lỗi xảy ra do người lập trình đưa ra các giả định sai và/hoặc thiếu khả năng phát hiện/xử lý lỗi thích hợp.

Trong bài này, chúng ta sẽ nói về các chiến lược xử lý lỗi.

Handling errors in functions

Hàm có thể lỗi bowie một vài lí do: 
người gọi có thể đã chuyển một đối số có giá trị không hợp lệ
một cái gì đó có thể bị lỗi trong phần thân của hàm
Handle the error within the function
Pass the error back to the caller to deal with
Halt the program
Throw an exception

1. Handling the error within the function
Nếu có thể, chiến lược tốt nhất là khắc phục lỗi trong cùng hàm đã xảy ra lỗi, để có thể ngăn chặn và sửa lỗi mà không ảnh hưởng đến bất kỳ mã nào bên ngoài hàm. Có hai lựa chọn ở đây: 
Thử lại cho đến khi thành công hoặc hủy thao tác đang được thực hiện.

2. Passing errors back to the caller
Trong nhiều trường hợp, lỗi không thể được xử lý một cách hợp lý trong hàm đã phát hiện lỗi. Ví dụ, ví dụ:
int doIntDivision(int x, int y)
{
    return x / y;
}
Trường hợp y = 0
Để xử lí
void printIntDivision(int x, int y)
{
    if (y != 0)
        std::cout << x / y;
    else
        std::cout << "Error: Could not divide by zero\n";
}
3. Fatal errors
Nếu lỗi nghiêm trọng đến mức chương trình không thể tiếp tục hoạt động bình thường thì đây được gọi là lỗi không thể phục hồi(non recoverable error) hoặc cũng có thể gọi là (fatal error)

4. Exceptions
Bởi vì việc trả lại lỗi từ một hàm cho người gọi rất phức tạp (và nhiều cách khác nhau để làm như vậy dẫn đến sự không nhất quán và sự không nhất quán dẫn đến sai sót), C++ đưa ra một cách hoàn toàn riêng biệt để chuyển lỗi trở lại cho người gọi: các ngoại lệ.(exception)
