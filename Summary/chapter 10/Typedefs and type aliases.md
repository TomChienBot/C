[Typedefs and type aliases](https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/)

1. Type aliases
Trong C++ using là từ khóa để tạo alias(bí danh) cho kiểu dữ liệu sẵn có.. Để tạo ra loại bị danh như vậy, ta sử dụng từ khóa using theo sau là tên cho bí danh và theo sau nữa là dấu bằng và loại dữ liệu hiện có.

using Distance = double; 

Sau khi được xác định, bí danh có thể được sử dụng ở bất kỳ nơi nào

2. Naming type aliases

BEST PRACTICE:

Đặt tên cho các bí danh loại của bạn bắt đầu bằng chữ in hoa và không sử dụng hậu tố (trừ khi bạn có lý do cụ thể để làm khác)

3. Type aliases are not distinct types

    using Miles = long; // define Miles as an alias for type long
    using Speed = long; // define Speed as an alias for type long

Mặc dù về mặt khái niệm, Miles and Speed có ý nghĩa riêng biệt, nhưng cả 2 chỉ là bí danh cho kiểu dữ liệu long. Miles, Speed and Long có thể sử dụng thay thế cho nhau.

4. The scope of a type alias

Bí danh (alias) tuân theo các quy tắc phạm vi tương tự như các mã định danh biến: bí danh được xác định bên trong một khối có phạm vi khối và chỉ có thể sử dụng được trong khối đó, trong khi một bí danh được xác định trong không gian tên chung có toàn cục. phạm vi và có thể sử dụng được đến cuối tập tin

5. Typedefs

Typedef (viết tắt của "định nghĩa kiểu") là một cách cũ hơn để tạo bí danh cho một loại. Để tạo bí danh typedef, chúng ta sử dụng từ khóa typedef

typedef long Miles;
using Miles = long;

typedef Distance double; // incorrect (typedef name first)
typedef double Distance; // correct (aliased type name first)

Best practice

Prefer type aliases over typedefs.

6. When should we use type aliases?

Using type aliases for platform independent coding

Một trong những mục đích sử dụng chính của bí danh loại là ẩn các chi tiết cụ thể của nền tảng. Trên một số nền tảng, int là 2 byte và trên các nền tảng khác là 4 byte.

Do đó, việc sử dụng int để lưu trữ hơn 2 byte thông tin có thể tiềm ẩn nguy hiểm khi viết mã độc lập với nền tảng.

Vì char, short, int và long không cho biết kích thước của chúng nên các chương trình đa nền tảng thường sử dụng bí danh để xác định bí danh bao gồm kích thước của loại theo bit.Ví dụ: int8_t sẽ là số nguyên có dấu 8 bit, int16_t là số nguyên có dấu 16 bit

using int8_t = char;
using int16_t = int;
using int32_t = long;

Using type aliases to make complex types easier to read

Ví dụ:
using VectPairSI = std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for this crazy type

bool hasDuplicates(VectPairSI pairlist) // use VectPairSI in a function parameter
{
    // some code here
    return false;
}

Tốt hơn nhiều! Bây giờ chúng ta chỉ cần gõ VectPairSI thay vì std::vector<std::pair<std::string, int>>.

Using type aliases to document the meaning of a value

using TestScore = int;
TestScore gradeTest();
Kiểu trả về của TestScore làm cho rõ ràng hơn một chút rằng hàm đang trả về loại đại diện cho điểm kiểm tra.

Using type aliases for easier code maintenance
Downsides and conclusion