[std::cin and handling invalid input](https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/)

1. std::cin, buffers, and extraction
Khi chúng ta sử dụng toán tử>> để lấy dữ liệu đầu vào của người dùng và đưa nó vào một biến, đây được gọi là extraction "trích xuất"
Khi người dùng nhập dữ liệu đầu vào để phản hồi thao tác trích xuất, dữ liệu đó sẽ được đặt vào bộ đệm bên trong std::cin
Bộ đệm buffer (còn gọi là bộ đệm dữ liệu) chỉ đơn giản là một phần bộ nhớ được dành để lưu trữ dữ liệu tạm thời trong khi nó được di chuyển từ nơi này sang nơi khác
Trích xuất thành công nếu có ít nhất một ký tự được trích xuất từ ​​bộ đệm đầu vào. Mọi thông tin đầu vào chưa được giải nén sẽ được để lại trong bộ đệm đầu vào để trích xuất trong tương lai.
Ví dụ:
int x{};
std::cin >> x;
Nếu nhấn 5a và bấm enter, 5 sẽ đc trích suất, chuyển thành số nguyên và gán cho biến x.
Nếu người dùng nhập 'b', việc trích xuất sẽ thất bại vì không thể trích xuất 'b' thành một biến số nguyên

2. Validating input(xác thực đầu vào)

Quá trình kiểm tra xem đầu vào của người dùng có phù hợp với những gì chương trình mong đợi hay không được gọi là xác thực đầu vào

Có 3 cách để xác thực:
cách 1: Ngăn chặn người dùng nhập thông tin nhập không hợp lệ ngay từ đầu.
cách 2: Cho phép người dùng nhập bất cứ thứ gì họ muốn vào một chuỗi, sau đó xác thực xem chuỗi đó có đúng hay không và nếu đúng thì hãy chuyển đổi chuỗi đó sang định dạng biến cuối cùng.
cách 3: Hãy để người dùng nhập bất cứ thứ gì họ muốn, để std::cin và operator>> thử giải nén nó và xử lý các trường hợp lỗi

3. A sample program
#include <iostream>

double getDouble()
{
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;
    return op;
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}

Error case 1: Extraction succeeds but input is meaningless

Ở đây yêu cầu nhập 1 trong 4 toán tử + - * / nhưng thay vào đó người dùng lại nhập "k". K là 1 kí tự hợp lệ, vì vậy std::cin có thể trích suất nó vào biến op và trả về main nhưng chương trình không mong đợi điều này sảy ra và không có cách xử lí chính xác với trường hợp này. (do đó không có output)

Error case 2: Extraction succeeds but with extraneous input
Enter a decimal number: 5*7
Khi nhập 5*7 làm đầu vào, nó sẽ được lưu ở bộ nhớ đệm. Tiếp đó toán tử >> sẽ trích xuất 5 làm biến x và giữ lại *7 ở bộ nhớ đệm.Tiếp theo, chương trình in ra "Nhập một trong các thông số sau: +, -, * hoặc /:". Tuy nhiên, khi toán tử trích xuất được gọi, nó thấy *7\n đang chờ trong bộ đệm để được trích xuất. Vì vậy nó sử dụng thay vì hỏi người dùng nhập thêm đầu vào. Kêts quả là nó chích xuất kí tự * và để 7 lại tại bộ nhớ.
Tiếp theo trương trình sẽ hỏi người dùng nhập tiếp số thập phân còn lại. Số 7 sẽ được trích xuất từ bộ nhớ đệm.

Mặc dù chương trình trên hoạt động nhưng việc thực thi rất lộn xộn. Sẽ tốt hơn nếu bỏ qua bất kỳ ký tự không liên quan nào được nhập vào. May mắn thay, thật dễ dàng để bỏ qua các ký tự:

std::cin.ignore(100, '\n');  // clear up to 100 characters out of the buffer, or until a '\n' character is removed

Để bỏ qua mọi thứ cho đến và bao gồm cả ký tự '\n' tiếp theo, chúng ta gọi
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
Vì câu lệnh khá dài nên ta có thể bỏ no vào hàm:

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;

    ignoreLine();
    return x;
}

Error case 3: Extraction fails ??
Enter a decimal number: a
Khi nhập a toán tử không thể trích xuất a sang dạng double. 2 điều sẽ xảy ra là a bị bỏ lại ở buffer và std::cin rơi vào trạng thái "failue mode"
Khi ở "chế độ lỗi", các yêu cầu trích xuất đầu vào trong tương lai sẽ không thành công. Vì vậy, trong chương trình máy tính của chúng tôi, lời nhắc đầu ra vẫn in ????
May mắn thay, chúng tôi có thể phát hiện liệu quá trình trích xuất có thất bại hay không:
if (std::cin.fail()) // If the previous extraction failed
{
    // Let's handle the failure
    std::cin.clear(); // Put us back in 'normal' operation mode ??
    ignoreLine();     // And remove the bad input
}

Sau khi quá trình trích xuất không thành công, các yêu cầu trích xuất đầu vào trong tương lai (bao gồm cả lệnh gọi bỏ qua()) sẽ âm thầm thất bại cho đến khi hàm clear() được gọi. Vì vậy, sau khi phát hiện quá trình trích xuất không thành công, việc gọi clear() thường là điều đầu tiên bạn nên làm.

Error case 4: Extraction succeeds but the user overflows a numeric value

Enter a number between -32768 and 32767: 40000
Enter another number between -32768 and 32767: The sum is: 32767

Trong trường hợp trên, std::cin ngay lập tức chuyển sang "chế độ lỗi", nhưng cũng gán giá trị trong phạm vi gần nhất cho biến. Do đó, x được giữ lại với giá trị được chỉ định là 32767. Các đầu vào bổ sung bị bỏ qua, để lại y với giá trị khởi tạo là 0. Chúng ta có thể xử lý loại lỗi này giống như cách trích xuất thất bại.