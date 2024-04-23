[Code Coverage](https://www.learncpp.com/cpp-tutorial/code-coverage/)

Thuật ngữ code coverage được sử dụng để mô tả lượng mã nguồn của chương trình được thực thi trong khi kiểm tra. 

Có nhiều số liệu khác nhau được sử dụng cho code coverage.

1. [Statement coverage](https://www.learncpp.com/cpp-tutorial/code-coverage/#:~:text=the%20following%20sections.-,Statement%20coverage,-The%20term%20statement)

Thuật ngữ statement coverage đề cập đến tỉ lệ phần trăm câu lệnh trong code của bạn đc thực hiển bởi thói quen kiểm tra.
ví dụ:

bool isLowerVowel(char c)
{
    switch (c) // statement 1
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true; // statement 2
    default:
        return false; // statement 3
    }
}
Hàm này sẽ phải gọi 2 lần để kiểm tra đc tất cả các trạng thái.

2. Branch coverage
Branch coverage đề cập tới tỷ lệ phần trăm số nhánh được thực hiện. Mỗi nhánh có thể được tính riêng lẻ
Ví dụ: Câu điều kiện if có 2 nhánh, 1 nhánh thực hiện khi điều kiện là True, và nhánh còn lại thực hiện khi điều kiện là False. 
Switch statement có thể có nhiều nhánh.

3. Loop coverage
Loop coverage thể hiện bằng việc bạn có 1 vòng lặp trong code, Phải đảm bảo rằng nó hoạt động bình thường khi lặp 0 lần, 1 lần và 2 lần. Nếu nó hoạt động đúng 2 lần, nó sẽ hoạt động đúng với các lần lặp lớn hơn 2.

4. Testing different categories of input
Một vài ví dụ của category testing:

Với kiểu integers, hay đảm bảo đã cân nhắc hàm sẽ sử lí giá trị âm, số 0 và số dương

Với string, hay đảm bảo xem hàm sẽ xử lí 1 chuỗi rỗng, 1 chuỗi chữ và số, chuỗi có khoảng trắng và chuỗi toàn khảng trắng như thế nào.
