[Floating-point and integral promotion](https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/)

Lưu ý rằng C++ có đảm bảo kích thước tối thiểu cho từng loại kiểu dữ liệu cơ bản. Tuy nhiên kích thước thực tế của những kiểu dữ liệu này có thể khác nhau dựa trên trình biên dịch và kiến trúc.

Sự thay đổi này được cho phép để các kiểu dữ liệu int và double có thể được đặt ở kích thước giúp tối đa hóa hiệu suất trên một kiến ​​trúc nhất định.

Ví dụ: 1 máy tính 32 bit thường xử lí 32 bits dữ liệu cùng 1 lúc. Trong trường hợp này. kiểu int có thể sẽ được đặt ở độ rộng 32 bit, vì đây là kích thước "tự nhiên" của dữ liệu mà CPU vận hành (và có thể là hiệu suất cao nhất).

A reminder: Số bit mà kiểu dữ liệu sử dụng được gọi là độ rộng của nó. Loại dữ liệu rộng hơn là loại sử dụng nhiều bit hơn và loại dữ liệu hẹp hơn là loại sử dụng ít bit hơn.

1. Numeric promotion

Vì C++ được thiết kế để di động và hoạt động tốt trên nhiều loại kiến trúc nên các nhà thiết kế ngôn ngữ không muốn cho rằng 1 CPU nhất định sẽ có thể thao tác hiệu quả trên giá trị hẹp hơn kích thước tự nhiên của cpu đó.

A numeric promotion: là loại chuyển đổi từ kiểu dữ liệu hẹp (ví dụ như char) sang kiểu dữ liệu dài hơn ( thường là int hoặc double) để có thể hoạt động hiểu quả hơn và chống chàn. 
Ví dụ: 
int main() {
    char c = 'A'; // 'A' có giá trị ASCII là 65
    short s = 100;

    // Khi thực hiện phép toán, c và s được tự động chuyển đổi lên kiểu int
    int sum = c + s; // Integral promotion: 'c' và 's' được chuyển đổi thành int trước khi cộng

    std::cout << "Kết quả của phép cộng là: " << sum << std::endl; // In ra 165

    return 0;
}


2. Numeric promotion reduces redundancy (Numeric promotion giảm sự dư thừa)

void printInt(int x)
{
    std::cout << x << '\n';
}

Kết quả hàm này in ra kiểu int, nếu ko có numeric promotion chúng ta muốn viết hàm cho kiểu short, hoặc char, hay unsigned char ,... chúng tả sẽ phải viết lại hàm này.

Numeric promotion có thể giúp ích ở đây chúng ta có thể viết các hàm có tham số int và/hoặc double (chẳng hạn như hàm printInt() ở trên). Sau đó, mã tương tự đó có thể được gọi với các đối số thuộc loại có thể được chuyển đổi về mặt số để khớp với loại của tham số hàm.

3. Numeric promotion categories
The numeric promotion có 2 loại:
integral promotions
floating point promotions

4. Floating point promotions

Quá trình chuyển đổi một giá trị của kiểu dữ liệu số thực như float lên kiểu dữ liệu số thực lớn hơn như double để thực hiện phép toán.

5. Integral promotions

Đây là quá trình chuyển đổi một giá trị của kiểu dữ liệu nguyên (ví dụ: char, short) lên một kiểu dữ liệu nguyên lớn hơn (ví dụ: int, long), thường là int, để thực hiện phép toán.

6. Not all widening conversions are numeric promotions

char to short, or int to long là numeric conversions not numeric promotion

promotion là một dạng chuyển đổi đặc biệt không làm thay đổi giá trị, trong khi conversions có thể bao gồm cả những chuyển đổi có thể làm thay đổi giá trị hoặc mất mát độ chính xác. 