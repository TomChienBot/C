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
