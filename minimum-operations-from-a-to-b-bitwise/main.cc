/*
  Suppose a and b. Find minimum number of bits that
  needs to choose to convert a into b
*/

#include <chrono>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

#define SIZE 11

// O(n) - n is a number of bits
constexpr int CountBits(int &number) {
  auto count{0};
  while (number > 0) {
    count += number & 1;
    number >>= 1;
  }

  return count;
}

// <= O(n) - n is a number of 1s bits
constexpr int FastBitCount(int &number) {
  auto count{0};
  while (number > 0) {
    ++count;
    number &= (number - 1);
  }

  return count;
}

inline constexpr int GetIthBit(int &number, int &position) {
  return number & (1 << position) != 0 ? 1 : 0;
}

inline constexpr void SetIthBitToOne(int &number, int &position) {
  auto mask = 1 << position;
  number |= mask;
}

inline constexpr void SetIthBitToZero(int &number, int &position) {
  auto mask = ~(1 << position);
  number &= mask;
}

constexpr int find_minimum_operations(int &a, int &b) {
  auto result{0};

  return result;
}

int main() {
  auto a = 13, b = 12;
  auto start = high_resolution_clock::now();
  cout << "Unique number is " << find_minimum_operations(a, b) << endl;
  // cout << "Number of bits is " << FastBitCount(a) << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "The time elapsed was " << duration.count() << " microseconds"
       << endl;
  return 0;
}