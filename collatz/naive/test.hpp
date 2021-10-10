#pragma once

#include <cassert>
#include <unordered_map>

void test() {
  std::unordered_map<ll, ll> values = {
      {1,1},
      {2, 2},
      {13, 10},
      {19, 21},
      {27, 112}
  };
  for (auto [input, expected] : values) {
    assert(collatz(input) == expected);
  }
}
