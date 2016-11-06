#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <vector>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::runtime_error;
using std::vector;

// this is a variation of the coin counting problem
// where coin values can be negative
class KSum
{
public:
  // TODO change vector to a generic collection
  // TODO bint types of 'target sum' and 'integers'
  KSum(const size_t k, const int targetSum, const vector< int > & integers):
      _k(k),
      _targetSum(targetSum),
      _integers(integers)
  {
    if (k > _integers.size()) {
      throw runtime_error("parameter k is too big"); // FIXME this should be an exception of custom type
    }
    // distinct is not unique, which is why we don't remove duplicates from 'integers' array
  }

  // TODO would be nice to have:
  //   setK()
  //   setTargetSum()
  //   appendIntegers(vector)

  const vector< int > calculateBruteForce() const
  {
    auto subsets = getAllSubsetsOfSizeK();
    for (auto subset = begin(subsets); subset != end(subsets); ++subset) {
      if (std::accumulate(begin(*subset), end(*subset), 0) == _targetSum) {
        return *subset; // let's assume we don't want to search for other combinations
      }
    }
    throw runtime_error("No combinations found"); // FIXME this should be an exception of custom type
  }


private:
  static const vector< int >
  getSelectedElementsFromVector(const vector< bool > & indices,
                                const vector< int > & source)
  {
    assert(indices.size() == source.size());
    vector< int > result;
    for (size_t i = 0; i < indices.size(); ++i) {
      if (indices[i]) {
        result.push_back(source[i]);
      }
    }
    return result;
  }

  const vector< vector< int > > getAllSubsetsOfSizeK() const
  {
    vector< vector< int > > result;
    vector< bool > indices(_integers.size(), false);
    for (size_t i = 0; i < _k; ++i) {
      indices[i] = true;
    }
    do {
      result.push_back(getSelectedElementsFromVector(indices, _integers));
    } while(std::prev_permutation(begin(indices), end(indices)));
    return result;
  }


  size_t _k;
  int _targetSum;
  vector< int > _integers;
};

int main()
{
  // TODO implement getting values from a file
  vector< int > positive = {7, 3, 6, 10, 43, 54, 2};
  KSum ksum51(3, 51, positive);
  cout << "These numbers add up to 51:" << endl;
  auto targetSubsetFor51 = ksum51.calculateBruteForce();
  for (auto elem = begin(targetSubsetFor51); elem != end(targetSubsetFor51); ++elem) {
    cout << *elem << ", ";
  }
  cout << endl;

  vector< int > ints = {7, -3, -6, 10, -9, 54, 2};
  KSum ksum6(3, 6, ints);
  cout << "These numbers add up to 6:" << endl;
  auto targetSubsetFor6 = ksum6.calculateBruteForce();
  for (auto elem = begin(targetSubsetFor6); elem != end(targetSubsetFor6); ++elem) {
    cout << *elem << ", ";
  }
  cout << endl;

  KSum ksum10(3, 10, ints);
  cout << "These numbers add up to 10:" << endl;
  try {
    auto targetSubsetFor10 = ksum10.calculateBruteForce();
  } catch (const runtime_error & error) {
    cout << error.what() << endl;
  }

  return 0;
}

