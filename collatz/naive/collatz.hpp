#pragma once

using ll = unsigned long long;

// returns cycle length for input N
ll collatz(ll n) {
  assert(n != 0);
  ll len = 1;
  for(; n != 1; ++len) {
    const bool isEven = n % 2 == 0;
    if (isEven) {
      n = n / 2;
    } else {
      n = 3 * n + 1; // does not account for overflow
    }
  }
  return len;
}
