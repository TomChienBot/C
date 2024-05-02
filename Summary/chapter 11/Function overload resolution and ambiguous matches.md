[Function overload resolution and ambiguous matches](https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/)

1. Resolving overloaded function calls
Khi một lệnh gọi hàm được thực hiện tới một hàm bị xếp chồng, trình biên dịch sẽ thực hiện một chuỗi các quy tắc để xác định hàm nào (nếu có) trong số các hàm bị xếp chồng là phù hợp nhất.

Quá trình này bao gồm các bước sau:

    1. Tìm Kiếm Phù Hợp Chính Xác: Trình biên dịch sẽ tìm kiếm hàm có danh sách tham số khớp chính xác với các đối số trong lời gọi hàm.
    2. Chuyển Đổi Kiểu: Nếu không tìm thấy phù hợp chính xác, trình biên dịch sẽ cố gắng áp dụng các chuyển đổi kiểu tự động (như chuyển đổi số nguyên sang số thực) để tìm kiếm hàm phù hợp.
    3. Ranking Các Phù Hợp: Nếu có nhiều hàm phù hợp sau khi áp dụng chuyển đổi kiểu, trình biên dịch sẽ xếp hạng các phù hợp dựa trên “độ tốt” của chuyển đổi kiểu.
    4. Chọn Hàm Phù Hợp Nhất: Cuối cùng, hàm có độ ưu tiên cao nhất sẽ được chọn.
Nếu trình biên dịch không thể tìm thấy một hàm phù hợp hoặc có quá nhiều hàm phù hợp mà không thể xác định được hàm nào là tốt nhất, nó sẽ báo lỗi.

Nếu nhiều hơn một hàm phù hợp đã được tìm thấy. Trình biên dịch sẽ đưa ra một lỗi biên dịch không khớp. ta sẽ nói thêm về điều này ở phần sau:

2. The argument matching sequence

Trong C++, chuỗi khớp đối số (argument matching sequence) là quá trình mà trình biên dịch sử dụng để xác định hàm nạp chồng nào phù hợp nhất với lời gọi hàm dựa trên các đối số được cung cấp. Khi có nhiều hàm cùng tên nhưng khác nhau về số lượng hoặc kiểu của tham số, trình biên dịch sẽ áp dụng một loạt quy tắc để chọn hàm phù hợp nhất1.

Quá trình này bao gồm các bước sau:

    1.Tìm Kiếm Phù Hợp Chính Xác: Trình biên dịch sẽ tìm kiếm hàm có danh sách tham số khớp chính xác với các đối số trong lời gọi hàm.
    2.Chuyển Đổi Kiểu: Nếu không tìm thấy phù hợp chính xác, trình biên dịch sẽ cố gắng áp dụng các chuyển đổi kiểu tự động (như chuyển đổi số nguyên sang số thực) để tìm kiếm hàm phù hợp.
    3.Xếp Hạng Các Phù Hợp: Nếu có nhiều hàm phù hợp sau khi áp dụng chuyển đổi kiểu, trình biên dịch sẽ xếp hạng các phù hợp dựa trên “độ tốt” của chuyển đổi kiểu.
    4.Chọn Hàm Phù Hợp Nhất: Cuối cùng, hàm có độ ưu tiên cao nhất sẽ được chọn.

3. Ambiguous matches

Với hàm ko bị xếp chồng, mỗi lệnh gọi hàm sẽ gọi ra 1 hàm, hoặc nếu ko tìm thấy hàm được gọi, trình biên dịch sẽ báo lỗi

Với hàm bị xếp chồng, có thể có 1 đầu ra thứ 3: tìm thấy 1 kết quả không rõ ràng. 

Kết quả không rõ ràng xảy ra khi trình biên dịch tìm thấy hai hoặc nhiều hàm có thể tìm thấy 2 hoặc nhiều hàm có thể khớp tròng cùng 1 bước.

ví dụ:
void print(int x) {
    std::cout << x << '\n';
}

void print(double d) {
    std::cout << d << '\n';
}

int main() {
    print('a'); // 'a' có thể được chuyển đổi tự động sang int hoặc double
    return 0;
}

4. Resolving ambiguous matches

Có 1 số cách giải quyết vấn đề này:

Thông thường cách tốt nhất là định nghĩa 1 hàm nạp chồng mới với danh sách tham số khớp chính xác với kiểu dữ liệu bạn muốn gọi hàm với. Bằng cách này, C++ sẽ có thể tìm thấy kết quả khớp chính xác cho lệnh gọi hàm.

Ngoài ra, hãy truyền rõ ràng (các) đối số không rõ ràng để khớp với loại hàm bạn muốn gọi. ví dụ:

int x{ 0 };
print(static_cast<unsigned int>(x)); // will call print(unsigned int)

Nếu đối số của bạn là một chữ, bạn có thể sử dụng hậu tố bằng chữ để đảm bảo chữ của bạn được hiểu là đúng loại:

ví dụ:

print(0u); // will call print(unsigned int) since 'u' suffix is unsigned int, so this is now an exact match

5. Matching for functions with multiple arguments

#include <iostream>

void print(char, int)
{
	std::cout << 'a' << '\n';
}

void print(char, double)
{
	std::cout << 'b' << '\n';
}

void print(char, float)
{
	std::cout << 'c' << '\n';
}

int main()
{
	print('x', 'a');

	return 0;
}

Trong chương trình trên, tất cả các hàm đều khớp chính xác với đối số đầu tiên. Tuy nhiên, hàm trên khớp với tham số thứ hai thông qua promotion, trong khi các hàm khác yêu cầu chuyển đổi. Do đó, print(char, int) rõ ràng là kết quả phù hợp nhất.