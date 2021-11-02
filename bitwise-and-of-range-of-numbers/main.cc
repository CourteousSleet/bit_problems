/*
  Given two integers start and end, return the bitwise AND of all numbers in
  [start, end], inclusive.

  Constraints:

  0 ≤ start ≤ end < 2**31
*/

#include <array>
#include <chrono>
#include <iostream>
#include <map>
#include <numeric>

using std::accumulate;
using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using namespace std::chrono;

#define SIZE 3
#define BITNESS 32