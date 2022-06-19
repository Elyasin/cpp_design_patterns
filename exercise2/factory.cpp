#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
    int counter = -1;
public:
  Person create_person(const string& name)
  {
      counter++;
      return Person{counter, name};
  }
};