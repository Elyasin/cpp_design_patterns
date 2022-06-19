#include <sstream>
#include <string>
#include <type_traits>

using namespace std;

template <template <class...> class F, class T>
struct is_from_template {
  static false_type test(...);

  template <class... U>
  static true_type test(const F<U...>&);

  static constexpr bool value = decltype(test(declval<T>()))::value;
};

struct Flower {
  virtual string str() = 0;
};

struct Rose : Flower {
  string str() override { return "A Rose"; }
};

template <typename T>
struct RedFlower : T {
  static_assert(is_base_of<Flower, T>::value,
                "Template argument must be a Flower");
  static_assert(!is_from_template<RedFlower, T>::value,
                "Template argument must not be RedFlower");

  RedFlower() {}

  template <typename... Args>
  RedFlower(Args&&... args) : T(forward<Args&&>(args)...) {}

  string str() override {
    ostringstream oss;
    oss << T::str() << " that is red";
    return oss.str();
  }
};

template <typename T>
struct BlueFlower : T {
  static_assert(is_base_of<Flower, T>::value,
                "Template argument must be a Flower");
  static_assert(!is_from_template<BlueFlower, T>::value,
                "Template argument must not be RedFlower");

  BlueFlower() {}

  template <typename... Args>
  BlueFlower(Args&&... args) : T(forward<Args&&>(args)...) {}

  string str() override {
    ostringstream oss;
    oss << T::str() << " that is blue";
    return oss.str();
  }
};
