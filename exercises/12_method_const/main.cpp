#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

/*
确保 get 方法可以在常量对象上调用，我们需要对 get 方法进行一些修改。
具体来说，我们需要将 get 方法声明为 constexpr 和 const，
以便它可以在编译时被调用，并且可以被常量对象使用。
*/

struct Fibonacci {
    int numbers[11];
    // TODO: 修改方法签名和实现，使测试通过
    constexpr int get(int i) const{
        return numbers[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
