#include <iostream>
#include <map>
#include <string>
#include <vector>

class CombinationLock {

  std::vector<int> combination;
  int pos = 0;

public:
  std::string status;

  CombinationLock(const std::vector<int> &combination)
      : combination(combination) {
    status = "LOCKED";
  }

  void enter_digit(int digit) {
    if (digit == combination[pos]) {
      if (pos == 0) {
        status = std::to_string(digit);
      } else {
        status += std::to_string(digit);
      }
      pos++;
      if (pos == combination.size()) {
        status = "OPEN";
      }
    } else {
      status = "ERROR";
    }
  }
};
