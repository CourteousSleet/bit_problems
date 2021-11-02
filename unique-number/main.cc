/*
  Find the unique number in a sequence of repeating numbers with only one unique
  number
*/

#include <iostream>
//#include <vector>
#include <array>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
// using std::vector;
using std::array;
using namespace std::chrono;

#define SIZE 11

constexpr int find_unique(const array<int, SIZE> numbers) {
  // constexpr int find_unique(const vector<int> numbers) {
  auto result{numbers.at(0)}, prev{0};
  for (auto index = 1; index < SIZE; ++index) {
    result ^= numbers.at(index);
  }
  return result;
}

int main() {
  auto start = high_resolution_clock::now();
  constexpr const array<int, SIZE> numbers{-1, 7, -1, 2, -7, 3, 3, 4, 4, 7, 2};
  // vector<int> numbers;
  // numbers.reserve(SIZE);
  // numbers = {1, 5, 1, 2, 6, 3, 3, 4, 4, 5, 2};
  cout << "Unique number is " << find_unique(numbers) << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "The time elapsed was " << duration.count() << " microseconds"
       << endl;
  return 0;
}