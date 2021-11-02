/*
  You are given a list of integers nums where each integer occurs exactly three
  times except for one which occurs once. Return the lone integer.
  Bonus: solve it in O(1) space.

  Constraints:

  n ≤ 100,000 where n is length of nums
*/

#include <algorithm>
#include <array>
#include <iostream>

using std::array;
using std::cin;
using std::cout;
using std::endl;

int main() {
  auto one_time{0u}, three_time{0u}, bit_mask{0u};
  constexpr const array<int, 4> list_of_numbers{1, 3, 1, 1};

  /*
  for (auto &number : list_of_numbers) {
    if (std::count(list_of_numbers.begin(), list_of_numbers.end(), number) !=
        3) {
      answer = number;
      break;
    }
  }*/

  for (auto i = 0; i < list_of_numbers.size(); ++i) {
    three_time = three_time | (one_time & list_of_numbers[i]);
    one_time = one_time ^ list_of_numbers[i];
    bit_mask = ~(one_time & three_time);

    one_time &= bit_mask;

    three_time &= bit_mask;
    
    cout << bit_mask << ' ' << three_time << ' ' << one_time << endl;
  }

  cout << one_time << endl;

  return 0;
}