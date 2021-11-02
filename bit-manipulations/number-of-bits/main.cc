/*
  Given an integer n, return the number of 1 bits in n.

  Constraints:

  0 ≤ n < 2 ** 31
*/

#include <bitset>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  auto number = 0u, answer = 0u;
  cin >> number;

  const auto binary = std::bitset<32>(number).to_string();
  cout << binary << endl;
  for (auto &i : binary)
    if (i == '1') ++answer;

  cout << answer << endl;

  return 0;
}