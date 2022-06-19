#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ContainsIntegers {
  virtual int getValue() const = 0;
};

struct SingleValue : ContainsIntegers {
  int value{0};

  SingleValue() = default;

  explicit SingleValue(const int value) : value{value} {}

  int getValue() const { return value; }
};

struct ManyValues : vector<int>, ContainsIntegers {
  int getValue() const {
    int s = 0;
    for (int v : *this) {
      s += v;
    }
    return s;
  }

  void add(const int value) { push_back(value); }
};

int sum(const vector<ContainsIntegers*> items);