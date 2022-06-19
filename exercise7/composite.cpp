#include "composite.hpp"

int sum(const vector<ContainsIntegers*> items) {
  int s = 0;
  for (auto item : items) {
    s += item->getValue();
  }
  return s;
}