#include <iostream>
#include <vector>

struct IRat {
  virtual void setAttack(int value) = 0;
};

struct Game {
  std::vector<IRat *> rats;

  void subscribe(IRat *rat) { rats.push_back(rat); }

  void unsubscribe(IRat *rat) {
    for (size_t i = 0; i < rats.size(); i++) {
      if (rat == rats[i]) {
        rats.erase(rats.begin() + i);
      }
    }
  }

  void updateAttacks() {
    for (auto &&rat : rats) {
      rat->setAttack(rats.size());
    }
  }
};

struct Rat : IRat {
  Game &game;
  int attack{1};

  Rat(Game &game) : game(game) {
    game.subscribe(this);
    game.updateAttacks();
  }

  ~Rat() {
    game.unsubscribe(this);
    game.updateAttacks();
  }

  void setAttack(int new_value) override { this->attack = new_value; }
};
