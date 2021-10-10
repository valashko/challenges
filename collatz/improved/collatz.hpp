#pragma once

#include <limits>
#include <stdexcept>

using ll = unsigned long long;

bool has_single_bit(ll x) { // https://en.cppreference.com/w/cpp/numeric/has_single_bit
  return x != 0 && (x & (x - 1)) == 0;
}

unsigned fast_log2(ll x) {
  return __builtin_ctzll(x); // tested on Apple Clang, should work on GCC as well
}

// returns Collatz sequence length for input N
ll collatz(ll n) {
  assert(n != 0);
  ll len = 1;
  for(; n != 1; ++len) {
    const bool isEven = n % 2 == 0;
    if (isEven) {
      if (has_single_bit(n)) return len + fast_log2(n);
      else n = n / 2;
    } else {
#ifdef CHECK_FOR_OVERFLOW
      if (n > ((std::numeric_limits<ll>::max() - 1) / 3)) {
        throw std::overflow_error("collatz: integer overflow");
      }
#endif
      n = 3 * n + 1;
    }
  }
  return len;
}
