#pragma once
#include <utility>

#if __cplusplus < 201103L
    #error "Must be compiled with C++11 support"
#endif

template<typename Result, typename... Args>
class cached_fn final
{
public:
    using Function = Result (*)(Args&&...);

    cached_fn(Function f);

    Result operator()(Args&&... args) const;

private:
    // ???
};

#if __cplusplus < 201703L
    // not required with C++17 because of implicitly-generated deduction guide
    template<typename Result, typename... Args>
    cached_fn<Result, Args...> make_cached(Result (*function)(Args&&...));
#endif
