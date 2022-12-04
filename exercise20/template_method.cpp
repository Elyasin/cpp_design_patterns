#include <complex>
#include <iostream>
#include <tuple>
#include <vector>

struct Creature {
  int attack, health;
  Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame {
  std::vector<Creature> creatures;

  CardGame(const std::vector<Creature> &creatures) : creatures(creatures) {}

  // return the index of the creature that won (is alive)
  // example:
  // - creature1 alive, creature2 dead, return creature1
  // - creature1 dead, creature2 alive, return creature2
  // - no clear winner: return -1
  int combat(int creature1, int creature2) {
    Creature &first = creatures[creature1];
    Creature &second = creatures[creature2];
    hit(first, second);
    hit(second, first);
    if (first.health <= 0 && second.health > 0) return creature2;
    if (first.health > 0 && second.health <= 0) return creature1;
    return -1;
  }

  virtual void hit(Creature &attacker, Creature &other) = 0;
};

struct TemporaryCardDamageGame : CardGame {
  TemporaryCardDamageGame(const std::vector<Creature> &creatures)
      : CardGame(creatures) {}

  void hit(Creature &attacker, Creature &other) override {
    if (attacker.attack >= other.health) other.health -= attacker.attack;
  }
};

struct PermanentCardDamageGame : CardGame {
  PermanentCardDamageGame(const std::vector<Creature> &creatures)
      : CardGame(creatures) {}

  void hit(Creature &attacker, Creature &other) override {
    other.health -= attacker.attack;
  }
};