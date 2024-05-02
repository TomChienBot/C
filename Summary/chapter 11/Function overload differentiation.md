[Function overload differentiation](https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/)(Phân biệt hàm quá tải )

Phân biệt hàm overload ntn :
Function property	    Used for differentiation	     Notes
Number of parameters	Yes	
Type of parameters	    Yes	                             Excludes typedefs, type aliases, and const qualifier on value parameter,..
Return type	            No	

1. Overloading based on number of parameters(Dựa trên số lượng tham số)

1 Hàm overload được cho là khác nhau miên là hàm có số lượng tham số khác nhau.
ví dụ:

int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

Overloading based on type of parameters (dựa trên kiểu tham số)

Một hàm cũng có thể được phân biệt miễn là danh sách các loại tham số của mỗi hàm quá tải là khác nhau

ví dụ:

int add(int x, int y); // integer version
double add(double x, double y); // floating point version
double add(int x, double y); // mixed version
double add(double x, int y); // mixed version

Trong C++, type alias (hoặc typedef) là một cách để đặt tên mới cho một kiểu dữ liệu đã tồn tại. Tuy nhiên, type alias không tạo ra một kiểu dữ liệu mới hoàn toàn, mà chỉ là một tên thay thế cho kiểu dữ liệu gốc. Điều này có một số hậu quả, trong đó có việc các hàm nạp chồng (overloaded functions) sử dụng type alias không được xem xét là khác biệt so với các hàm nạp chồng sử dụng kiểu dữ liệu gốc.

ví dụ:

typedef int Height; // typedef
using Age = int; // type alias

void print(int value);
void print(Age value); // not differentiated from print(int)
void print(Height value); // not differentiated from print(int)

3. The return type of a function is not considered for differentiation

Trong C++, khi nạp chồng hàm (overloading functions), kiểu trả về của hàm không được sử dụng để phân biệt giữa các hàm nạp chồng. Điều này có nghĩa là bạn không thể có nhiều hàm cùng tên chỉ khác nhau ở kiểu trả về.

Ví dụ:
int foo() {
    return 42;
}

double foo() {
    return 3.14;
}

4. type Signature

 chữ ký kiểu (type signature) của một hàm định nghĩa các đầu vào và đầu ra của hàm đó. Chữ ký kiểu bao gồm số lượng, kiểu và thứ tự của các đối số mà hàm nhận vào

 Ví dụ: int add(int a, int b); // Chữ ký kiểu là (int, int) -> int

Trong ví dụ trên, hàm add có chữ ký kiểu là (int, int) -> int, nghĩa là nó nhận vào hai đối số kiểu int và trả về một giá trị kiểu int.