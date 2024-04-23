[Common semantic errors in C++](https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/)(Lỗi ngữ nghĩa)
Lỗi ngữ nghĩa, lỗi xảy ra khi viết code mà nó không họa động theo những gì mong muốn. Trình biến dịch sẽ không bắt lỗi ngữ nghĩa (Trong 1 số trường hợp, những trình biên dịch tiên tiến hơn sẽ có thể tạo cảnh báo)

Dưới đây là 1 vài lỗi ngữ nghĩa phổ biến nhất xay ra trong C++ :

1. Conditional logic errors
A conditional logic errors xảy ra khi lập trình viên lập trình sai code logic câu lệnh điều kiện hoặc điều kiện của vòng lặp.

ví dụ:
int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    if (x >= 5) // oops, we used operator>= instead of operator>
        std::cout << x << " is greater than 5\n";

    return 0;
}

2. infinite loops
ví dụ: 

int main()
{
    int count{ 1 };
    while (count <= 10) // this condition will never be false
    {
        std::cout << count << ' '; // so this line will repeatedly execute
    }

    std::cout << '\n'; // this line will never execute

    return 0; // this line will never execute
}

Kết quả in ra sẽ lặp vô hạn số 1.

3. Off-by-one errors(lỗi lẻ tẻ):

Lỗi này xảy ra khi vòng lặp lặp lại quá nhiều lần hoặc quá ít lần so với yêu cầu.

Ví dụ muốn dùng lệnh for để in ra màn hình 1,2,3,4,5
for (int count{ 1 }; count < 5; ++count)
    {
        std::cout << count << ' ';
    }
nếu dùng dấu < thay vì dấu <= thì sẽ chỉ in ra 1,2,3,4

4. Incorrect operator precedence:
int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!x > y) // oops: operator precedence issue
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}

Bởi vì ! được đặt trước > nên câu kiện của if có thể được hiểu thành !(x) > y

5. Precision issues with floating point types

(float và double) chỉ lưu trữ một số lượng nhất định các chữ số có nghĩa, và phần còn lại sẽ bị mất.
Theo mặc định, cout có độ chính xác 6 chữ số thập phân khi xuất số điểm nổi.
Bất cứ thứ gì vượt quá 6 chữ số thập phân sẽ bị cắt bỏ.

Ví dụ:
Trong ví dụ của bạn, giá trị 0.123456789f có nhiều hơn 6 chữ số thập phân.
Khi in ra bằng cout, nó được làm tròn đến giá trị có thể biểu diễn gần nhất với 6 chữ số thập phân.
Kết quả bạn thấy sẽ là 0.123457

6. Accidental null statements

null statements là những câu lệnh không làm gì cả và chuyển tiếp xuống câu lệnh dưới
ví dụ:

    if (c == 'y');     // accidental null statement here
        blowUpWorld(); // so this will always execute since it's not part of the 

7. Not using a compound statement when one is required
ví dụ:

if (c == 'y')
        std::cout << "Okay, here we go...\n";
        blowUpWorld(); // Will always execute.  Should be inside compound statement.

8. Using assignment instead of equality inside a conditional

= là toán tử gán giá trị
== là toán tử so sánh.