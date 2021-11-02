/*
  Given an integer n, return the total number of set bits in all integers
  between 1 and n inclusive.

  This should be done in O(logn).

  Constraints:

  n ≤ 2 ** 27
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

constexpr int FastBitCount(const int &number) {
  auto count{0}, _number{number};
  while (_number > 0) {
    ++count;
    _number &= (_number - 1);
  }

  return count;
}

constexpr unsigned int CountSetBitsUtil(unsigned int x) {
  if (x <= 0) return 0;
  return (x % 2 == 0 ? 0 : 1) + CountSetBitsUtil(x / 2);
}

constexpr int FindBitsSet(int &number) {
  auto result{0};

  while (number >= 1) {
    result += FastBitCount(number);
    number -= 1;
  }

  return result;
}

constexpr int SlowMethod(int &number) {
  auto bit_count = 0, _number{number};

  for (auto i = 1; i <= _number; ++i) bit_count += CountSetBitsUtil(i);

  return bit_count;
}

// Хуйня
constexpr int AverageMethod(int &number) {
  auto i = 0;
  auto ans = 0;

  while ((1 << i) <= number) {
    auto k = false;
    auto change = 1 << i;
    for (auto j = 0; j <= number; j++) {
      ans += k;
      if (change == 1) {
        k = !k;
        change = 1 << i;
      } else
        --change;
    }
    ++i;
  }

  return ans;
}

// Самое чётенькое
inline constexpr int FastMethod(int number) {
  if (number <= 1) return number;
  auto FindHighestPower = [&](int n) -> int {
        int x = 0;
        while ((1 << x) <= n) x++;
        return x - 1;
    };
  int x = FindHighestPower(number);
  return (x * pow(2, (x - 1))) + (number - pow(2, x) + 1) +
         FastMethod(number - pow(2, x));
}

constexpr int ChooseThePlan(unsigned int &state, int &number) {
  switch (state) {
    case 0:
      cout << "Slow Method..." << endl;
      return SlowMethod(number);

    case 1:
      cout << "O(k*n)" << endl;
      return AverageMethod(number);

    case 2:
      cout << "O(logn)" << endl;
      return FastMethod(number);

    default:
      cout << "First Idea" << endl;
      return FindBitsSet(number);
  }
}

int main() {
  auto number = 134217728;
  auto state = 3u;
  cout << "Choose methods:" << endl
       << "I. Slowest Method (O(n*logn))" << endl
       << "II. O(k*n) method" << endl
       << "III. O(logn) method" << endl
       << "Your choice: ";
  cin >> state;
  auto start = high_resolution_clock::now();
  cout << "Set bits is " << ChooseThePlan(state, number) << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "The time elapsed was " << duration.count() << " microseconds"
       << endl;
  return 0;
}