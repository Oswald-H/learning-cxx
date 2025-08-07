#include "../exercise.h"

template <uintmax_t n>
struct fib {
    static constexpr uintmax_t value = fib<n - 1>::value + fib<n - 2>::value;
};

template <> struct fib <0> {    
    static constexpr uintmax_t value = 0;
};

template <>
struct fib<1> {
    static constexpr uintmax_t value = 1;
};

int main(int argc, char **argv) {
    // constexpr auto FIB20 = fibonacci(20);
    constexpr auto FIB20 = fib<20>::value;
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fib<ANS_N>::value;
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
