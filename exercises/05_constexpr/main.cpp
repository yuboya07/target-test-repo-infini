#include "../exercise.h"

// 辅助函数，使用尾递归来计算斐波那契数列
constexpr unsigned long long fibonacci_helper(int i, unsigned long long a = 0, unsigned long long b = 1) {
    if (i == 0) return a;
    if (i == 1) return b;
    return fibonacci_helper(i - 1, b, a + b);
}

constexpr unsigned long long fibonacci(int i) {
    return fibonacci_helper(i);
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
