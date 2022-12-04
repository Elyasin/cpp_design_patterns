#include <iostream>
#include <vector>

struct IParticipant {
  virtual void increment(int value) = 0;
};

struct Mediator {
  std::vector<IParticipant *> participants;
};

struct Participant : IParticipant {
  int value{0};
  Mediator &mediator;

  Participant(Mediator &mediator) : mediator(mediator) {
    mediator.participants.push_back(this);
  }

  void say(int value) {
    for (auto &&p : mediator.participants) {
      if (p != this) {
        p->increment(value);
      }
    }
  }

  void increment(int value) override { this->value += value; }

  void print() { std::cout << "value is " << this->value << std::endl; }
};