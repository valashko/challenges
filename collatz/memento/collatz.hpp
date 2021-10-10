#pragma once

#include <unordered_map>

using ll = unsigned long long;

// returns Collatz sequence length for input N
class Collatz {
public:
  ll operator()(ll n) {
    static constexpr ll long_seq = 30; // needs to be tweaked based on performance measurements
    auto len = impl(n);
    if (len > long_seq) known_values[n] = len;
    return len;
  }

private:
  ll impl(ll n) {
    assert(n != 0);
    ll len = 1;
    for (; n != 1; ++len) {
      if (auto v = known_values.find(n); v != known_values.cend()) {
        return len + v->second - 1;
      }
      const bool isEven = n % 2 == 0;
      if (isEven) {
        n = n / 2;
      } else {
        n = 3 * n + 1;
      }
    }
    return len;
  }

  std::unordered_map<ll, ll> known_values;
};
