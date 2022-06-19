#include <string>

class IPerson {
  virtual int get_age() const = 0;
  virtual void set_age(int age) = 0;
  virtual std::string drink() const = 0;
  virtual std::string drive() const = 0;
  virtual std::string drink_and_drive() const = 0;
};

class Person : IPerson {
  friend class ResponsiblePerson;
  int age;

 public:
  Person(int age) : age(age) {}
  Person(const Person &person) : age{person.age} {};

  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }

  std::string drink() const { return "drinking"; }
  std::string drive() const { return "driving"; }
  std::string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson : IPerson {
  Person person;

 public:
  ResponsiblePerson(const Person &p) : person{p} {}

  int get_age() const { return person.age; }
  void set_age(int age) { person.age = age; }

  std::string drink() const {
    if (person.age < 18) return "too young";
    return person.drink();
  }
  std::string drive() const {
    if (person.age < 16) return "too young";
    return person.drive();
  }
  std::string drink_and_drive() const { return "dead"; }
};