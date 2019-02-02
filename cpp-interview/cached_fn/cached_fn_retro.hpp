#pragma once


template<typename Result, typename Arg1>
class cached_fn_1
{
public:
    typedef Result (*Function)(Arg1);

    cached_fn_1(Function f);

    Result operator()(Arg1 arg1) const;

private:
    // ???
};

template<typename Result, typename Arg1, typename Arg2>
class cached_fn_2
{
public:
    typedef Result (*Function)(Arg1, Arg2);

    cached_fn_2(Function f);

    Result operator()(Arg1 arg1, Arg2 arg2) const;

private:
    // ???
};

// up to required arity
// class cached_fn_3;
// ...
// class cached_fn_n;

template<typename Result, typename Arg1>
cached_fn_1<Result, Arg1> make_cached(Result (*function)(Arg1));

template<typename Result, typename Arg1, typename Arg2>
cached_fn_2<Result, Arg1, Arg2> make_cached(Result (*function)(Arg1, Arg2));

// up to required arity
// make_cached(ternary function);
// ...
// make_cached(n-ary function);
