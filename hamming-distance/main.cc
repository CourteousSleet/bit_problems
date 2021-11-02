/*
  Given two integers x, and y return the number of positions where their values
  differ in their binary representations as a 32-bit integer.

  Constraints

  0 ≤ x, y < 2 ** 31
*/

#include <bitset>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  auto x = 0u, y = 0u, answer = 0u;
  cin >> x >> y;

  const auto x_binary = std::bitset<32>(x).to_string();
  const auto y_binary = std::bitset<32>(y).to_string();
  cout << x_binary << endl << y_binary << endl;
  
  for (auto index = 0; index < 32; ++index)
    if (x_binary.at(index) != y_binary.at(index)) ++answer;

  cout << answer << endl;

  return 0;
}