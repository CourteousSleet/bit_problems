/*
  Given an integer n greater than or equal to 0, return whether it is a power of
  two.

  Constraints

  0 ≤ n < 2 ** 31
*/

#include <bitset>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  auto number = 0u, numbers = 0u;
  auto answer = false;
  cin >> number;

  const auto binary = std::bitset<32>(number).to_string();
  cout << binary << endl;
  for (auto &i : binary)
    if (i == '1') ++numbers;

  if (numbers == 1) answer = true;

  cout << answer << endl;

  return 0;
}