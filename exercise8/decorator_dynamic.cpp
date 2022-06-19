#include <sstream>
#include <string>

using namespace std;

struct Flower {
  virtual string str() = 0;
};

struct Rose : Flower {
  string str() override { return "A Rose"; }
};

struct RedFlower : Flower {
  Flower &flower;
  RedFlower(Flower &flower) : flower{flower} {}

  string str() override {
    ostringstream oss;
    if (flower.str().find("that is") == string::npos) {
      oss << flower.str() << " that is red";
    } else if (flower.str().find("red") == string::npos) {
      oss << flower.str() << " and red";
    } else {
      oss << flower.str();
    }
    return oss.str();
  }
};

struct BlueFlower : Flower {
  Flower &flower;
  BlueFlower(Flower &flower) : flower{flower} {}

  string str() override {
    ostringstream oss;
    if (flower.str().find("that is") == string::npos) {
      oss << flower.str() << " that is blue";
    } else if (flower.str().find("blue") == string::npos) {
      oss << flower.str() << " and blue";
    } else {
      oss << flower.str();
    }
    return oss.str();
  }
};