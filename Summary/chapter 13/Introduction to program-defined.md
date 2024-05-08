[Introduction to program-defined (user-defined) types](https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/)

Những Kiểu dữ liệu cơ bản được định nghĩa là 1 phần lõi của C++. Chúng có sẽ để có thể sử dụng ngay lập tức. 

Ví dụ: Muốn định nghĩa 1 biến với kiểu int hay double , chỉ cần: 
    int x; // define variable of fundamental type 'int'
    double d; // define variable of fundamental type 'double'

Điều này cũng đúng với kiểu dữ liệu kết hợp là phần mở rộng cơ bản của dữ liệu cơ bản (hàm, con trỏ, tham chiếu và mảng):

    void fcn(int) {}; // define a function of type void()(int)
    int* ptr; // define variable of compound type 'pointer to int'
    int& ref { x }; // define variable of compound type 'reference to int' (initialized with x)
    int arr[5]; // define an array of 5 integers of type int[5] (we'll cover this in a future chapter)

Các định nghĩa này sẽ hoạt động vì C++ biết tên loại dữ liệu (hoặc kí hiệu) có ý nghĩa là gì. Ta sẽ không cần cung cấp bất kì định nghĩa nào để sử dụng

Trường hợp của type alias. Bởi vì alias giới thiệu 1 định danh mới vào chương trình, type alias (bí danh ) Phải được định nghĩa trước khi sử dụng:

    using length = int; // define a type alias with identifier 'length'

1. What are user-defined / program-defined types?

Trong chapter  (12.1 -- Introduction to compound data types) đã giới thiệu 1 thử thách về lưu trữ 1 phân số, trong đó có tử số và mẫu số được liên kết về mặt khái niệm với nhau. Trong bài này chúng ta đã thảo luận về một số thách thức khi sử dụng hai số nguyên riêng biệt để lưu trữ tử số và mẫu số của một phân số một cách độc lập. 

Nếu C++ có kiểu phân số, mọi chuyện đã dễ dàng, nhưng không có

Thay vào đó, C++ giải quyết những vấn đề như vậy theo một cách khác: bằng cách cho phép chúng ta tạo các kiểu tùy chỉnh, hoàn toàn mới để sử dụng trong các chương trình của mình! Những kiểu dữ liệu dạng này được gọi là user - defined types .Những kiểu như vậy thường được gọi là kiểu do người dùng xác định (mặc dù chúng tôi cho rằng thuật ngữ kiểu do chương trình xác định là tốt hơn -- chúng ta sẽ thảo luận về sự khác biệt sau trong bài học này).

C++ có hai loại kiểu ghép khác nhau có thể được sử dụng để tạo các kiểu do chương trình xác định (program-defined types):

    Enumerated types
    Class types

2. Defining program-defined types

Theo quy ước, program-defined types được đặt tên bắt đầu bằng chữ in hoa và không sử dụng hậu tố

    Fraction fraction {}; // Instantiates a variable named fraction of type Fraction

3. Using program-defined types throughout a multi-file program

Best practice:

    A program - defined type chỉ được sử dụng trong một tệp mã phải được xác định trong tệp mã đó càng gần điểm sử dụng đầu tiên càng tốt.

    A program-defined type được sử dụng trong nhiều tệp mã phải được xác định trong tệp tiêu đề có cùng tên với program-defined type và sau đó #included vào mỗi tệp mã nếu cần.

Ví dụ:

Faction.h

    #ifndef FRACTION_H
    #define FRACTION_H

    // Define a new type named Fraction
    // This only defines what a Fraction looks like, it doesn't create one
    // Note that this is a full definition, not a forward declaration
    struct Fraction
    {
        int numerator {};
        int denominator {};
    };

    #endif

Faction.cpp
    #include "Fraction.h" // include our Fraction definition in this code file

    // Now we can make use of our Fraction type
    int main()
    {
        Fraction f{ 3, 4 }; // this actually creates a Fraction object named f

        return 0;
    }

3. Type definitions are partially exempt from the one-definition rule (ODR)

Quy tắc một định nghĩa (ODR) :
    yêu cầu chỉ có một định nghĩa cho mỗi biến, hàm, kiểu dữ liệu, kiểu liệt kê, ... trong toàn bộ chương trình. Tuy nhiên, định nghĩa kiểu dữ liệu có một chút "khoan nhượng".

Chúng ta có thể dùng foward declaration để sử dụng 1 hàm hoặc 1 biến toàn cục trong file mà không chứa định nghĩa

Tuy nhiên việc sử dụng forward declaration không hoạt động với types bởi vì trình biên dịch cần xem toàn bộ định nghĩa để sử dụng 1 kiểu dữ liệu cho sẵn.

Vì vậy chúng ta cần phải truyền đầy đỉ định nghĩa kiểu dữ liệu tới từng file cần nó.

Để cho phép điều này, các loại được miễn một phần khỏi quy tắc một định nghĩa: một kiểu dữ liệu cho trước được phép định nghĩa trong nhiều tệp mã

Ví dụ:
tệp point.h:

    struct Point {
    int x;
    int y;
    };

Ta có thể sử dụng kiểu dữ liệu này trong nhiều tệp nguồn khác nhau:
main.cpp:

    #include "point.h"

    int main() {
    Point p {1, 2};
    // ...
    }

geometry.cpp:

    #include "point.h"

    double distance(const Point& p1, const Point& p2) {
    // ...
    }

Trong ví dụ này, kiểu dữ liệu Point được định nghĩa trong point.h và được bao gồm trong cả main.cpp và geometry.cpp. Mặc dù Point được định nghĩa trong cả hai tệp, nhưng không có vi phạm ODR vì các định nghĩa giống hệt nhau.

4. Nomenclature: user-defined types vs program-defined types (Danh pháp: loại do người dùng xác định và loại do chương trình xác định)

    Type	                                            Meaning	                                                                    Examples
    Fundamental	                        A type built into the core C++ language	                                                int, std::nullptr_t
    Compound	                        A type built from fundamental types	                                                    int&, double*, std::string, Fraction
    User-defined	                    A class type or enumerated type(Includes those defined in the standard library          std::string, Fraction
                                        or implementation)(In casual use, typically used to mean program-defined            types)	                                                                                        
    Program-defined	                    A class type or enumerated type(Excludes those defined in standard library              Fraction
                                        or implementation)	                                                            
