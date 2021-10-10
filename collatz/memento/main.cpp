// Assumptions:
// - input is well-formed (no exquisite checks are needed)
// - input is in base 10
// - "below which the longest ..." interpreted as "strictly below (<)"
// - the smallest number (if multiple exist) having the longest sequence is the answer

#include <iostream>
#include <stdexcept>
#include <string>

#include "collatz.hpp"
#include "test.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
  test(); // poor man's test due to 1 hour limit

  try {
    if (argc != 2) throw runtime_error("single argument please");
    auto limit = stoull(string(argv[1]));
    ll start = 0, seq_len = 0;
    Collatz collatz;
    for (ll i = 1; i < limit; ++i) {
      if (auto candidate = collatz(i); candidate > seq_len) {
        start = i;
        seq_len = candidate;
      }
    }
    cout << "Starting number " << start <<" has the longest sequence of "
         << seq_len << "\n";
  } catch (const exception & e) {
    cerr << e.what() << "\n";
    return 1;
  }
}
