/*
  You are given three positive integers a, b and target. Consider an operation
  where you take either a or b and update one of the bits to 1 or to 0.

  Return the minimum number of operations required to make a | b = target.

  Constraints:

  1 ≤ a, b, target < 2 ** 31
*/

#include <bitset>
#include <chrono>
#include <iostream>

using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std::chrono;

#define SIZE 32

// 12 ms, O(3 * SIZE) - space
int find_minimum_operations(int &a, int &b, int &target) {
  auto result{0};
  auto a_binary = bitset<SIZE>(a).to_string();
  auto b_binary = bitset<SIZE>(b).to_string();
  auto target_binary = bitset<SIZE>(target).to_string();
  cout << a_binary << endl << b_binary << endl << target_binary << endl << endl;

  for (auto index = 0; index < SIZE; ++index) {
    switch (target_binary.at(index)) {
      case '1':
        if (a_binary.at(index) != '1' && b_binary.at(index) != '1') ++result;
        break;

      case '0':
        if (a_binary.at(index) == '1' && b_binary.at(index) == '1')
          result += 2;
        else if (a_binary.at(index) == '1' || b_binary.at(index) == '1')
          ++result;
        break;

      default:
        break;
    }
  }

  return result;
}

// 0.5 ms, O(1) - space
int fast_find_minimum_operations(int &a, int &b, int &target) {
  auto result{0};
  for (auto i = 0; i < SIZE; ++i) {
    auto mask = 1 << i;
    if (target & mask) {
      if ((a & mask) || (b & mask)) continue;
      result++;
    } else {
      if (a & mask) result++;
      if (b & mask) result++;
    }
  }
  return result;
}

int main() {
  auto a = 2, b = 4, target = 8;
  auto start = high_resolution_clock::now();
  cout << "Minimum bits to be changed is "
       << fast_find_minimum_operations(a, b, target) << endl;
  //       << find_minimum_operations(a, b, target) << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "The time elapsed was " << duration.count() << " microseconds"
       << endl;
  return 0;
}