/*
  You are given a list of integers nums and an integer k. You must perform this
  operation k times:
    1. Choose any number on the list. In the binary representation of the
  number, choose a bit that is 0 and make it 1.
    2. Return the minimum possible sum of all the numbers (mod 10 ** 9 + 7)
  after performing k operations.

  Constraints:

  k < n where n is the length of nums.
  nums[i] ≤ 10 ** 9.
*/

#include <array>
#include <chrono>
#include <iostream>
#include <numeric>

using std::accumulate;
using std::array;
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

#define SIZE 3
#define BITNESS 32

int FindMinSum(const array<unsigned int, SIZE> &_numbers,
               unsigned int &_ops_number) {
  array<unsigned int, BITNESS> bits_positions_array = {0};
  auto sum = 0;

  for (auto index = 0; index < BITNESS; ++index) {
    for (auto subindex = 0u; subindex < SIZE; ++subindex) {
      auto inter_var = _numbers.at(subindex);
      auto _index = index;
      if (inter_var & (1 << _index) == 1) {
        cout << inter_var << " & (1 << " << _index << ") " << endl;
        ++bits_positions_array.at(index);
      }
    }
  }

  for (auto index = 0; index < BITNESS; ++index) {
    if (_ops_number == 0)
      break;
    else if (bits_positions_array.at(index) == SIZE)
      continue;
    else {
      while (bits_positions_array.at(index) != SIZE && _ops_number != 0) {
        ++bits_positions_array.at(index);
        --_ops_number;
      }
    }
  }

  for (auto index = 0; index < BITNESS; ++index)
    sum += bits_positions_array.at(index) * pow(2, index);

  return sum;
}

int FastFindMinSum(const array<unsigned int, SIZE> _numbers,
                   unsigned int &_ops_number) {
  auto index_of_bit = 1;
  auto increasing_sum = 0;
  auto base = accumulate(_numbers.begin(), _numbers.end(),
                         decltype(_numbers)::value_type(0));

  while (_ops_number) {
    for (auto &num : _numbers) {
      if ((num | index_of_bit) ^ num) {
        --_ops_number;
        increasing_sum += index_of_bit;
      }
      if (!_ops_number) break;
    }
    index_of_bit <<= 1;
  }
  return (base + increasing_sum) % (1'000'000'007);
}

int main() {
  array<unsigned int, SIZE> numbers{3, 7, 3};
  auto ops_number = 2u;

  auto start = high_resolution_clock::now();
  cout << "Minimum sum would be " << FastFindMinSum(numbers, ops_number)
       << endl;
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "The time elapsed was " << duration.count() << " microseconds"
       << endl;
  return 0;
}