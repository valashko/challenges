#include <iostream>

#if __cplusplus >= 201103L
    #include "cached_fn_modern.hpp"
#else
    #include "cached_fn_retro.hpp"
#endif


double half(int i)
{
    std::cout << "half(" << i << ")\n";
    return i / 2.;
}

int sum(int i, int j)
{
    std::cout << "sum(" << i << "," << j << ")\n";
    return i + j;
}

int main(int argc, const char* argv[])
{
    #if __cplusplus >= 201703L
        cached_fn half_cached{half};
        cached_fn sum_cached{sum};
    #elif __cplusplus >= 201103L
        auto half_cached = make_cached(half);
        auto sum_cached = make_cached(sum);
    #else
        cached_fn_1<double, int> half_cached = make_cached(half);
        cached_fn_2<int, int, int> sum_cached = make_cached(sum);
    #endif

    std::cout << "half_cached(10) = " << half_cached(10) << '\n';
    std::cout << "half_cached(20) = " << half_cached(20) << '\n';
    std::cout << "sum_cached(3, 5) = " << sum_cached(3, 5) << '\n';

    std::cout << "repetition\n";
    std::cout << "half_cached(10) = " << half_cached(10) << '\n';
    std::cout << "half_cached(10) = " << half_cached(10) << '\n';
    std::cout << "half_cached(10) = " << half_cached(10) << '\n';
    std::cout << "sum_cached(3,5) = " << sum_cached(3, 5) << '\n';
    std::cout << "sum_cached(3,5) = " << sum_cached(3, 5) << '\n';

    /* expected output:

       half(10)
       half_cached(10) = 5
       half(20)
       half_cached(20) = 10
       sum(3,5)
       sum_cached(3,5) = 8
       repetition
       half_cached(10) = 5
       half_cached(10) = 5
       half_cached(10) = 5
       sum_cached(3,5) = 8
       sum_cached(3,5) = 8
     */

    return 0;
}
