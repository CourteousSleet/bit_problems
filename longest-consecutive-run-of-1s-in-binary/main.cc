/*
  Given a non-negative integer n, return the length of the longest consecutive
  run of 1s in its binary representation.

  Constraints:

  0 ≤ n < 2 ** 31
*/

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::max_element;
using std::vector;

int main() {
  auto number = 0u, answer = 0u;
  cin >> number;

  /*
  const auto binary = bitset<32>(number).to_string();
  vector<unsigned int> substrs{};
  cout << binary << endl;

  for (auto ch = 0; ch <= binary.length(); ++ch) {
    if (ch == binary.length() - 1) {
      if (binary[ch] == '1') substrs.emplace_back(++answer);
    } else {
      if (binary[ch] == '1')
        ++answer;
      else {
        substrs.emplace_back(answer);
        answer = 0u;
      }
    }
  }

  cout << *max_element(substrs.cbegin(), substrs.cend()) << endl;
  */

  while (number != 0) {
    number = (number & (number << 1));
    answer++;
  }

  cout << answer << endl;

  return 0;
}