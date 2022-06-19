#include <vector>

template <typename Base, typename T>
inline bool instanceof (const T *ptr) {
  return dynamic_cast<const Base *>(ptr) != nullptr;
}

struct Creature;
struct Game {
  std::vector<Creature *> creatures;
};

struct StatQuery {
  enum Statistic { attack, defense } statistic;
  int result;
};

struct Creature {
 protected:
  Game &game;
  int base_attack, base_defense;

 public:
  Creature(Game &game, int base_attack, int base_defense)
      : game(game), base_attack(base_attack), base_defense(base_defense) {}
  virtual int get_attack() = 0;
  virtual int get_defense() = 0;
  virtual void query(Creature *creature, StatQuery &sq) = 0;
};

class Goblin : public Creature {
 public:
  Goblin(Game &game, int base_attack, int base_defense)
      : Creature(game, base_attack, base_defense) {}

  Goblin(Game &game) : Creature(game, 1, 1) {}

  int get_attack() override {
    StatQuery sq{StatQuery::Statistic::attack, 0};
    for (auto &&creature : game.creatures) {
      creature->query(this, sq);
    }
    return sq.result;
  }

  int get_defense() override {
    StatQuery sq{StatQuery::Statistic::defense, 0};
    for (auto &&creature : game.creatures) {
      creature->query(this, sq);
    }
    return sq.result;
  }

  void query(Creature *creature, StatQuery &sq) override {
    if (this == creature) {
      if (sq.statistic == StatQuery::attack)
        sq.result += base_attack;
      else
        sq.result += base_defense;
    } else {
      if (sq.statistic == StatQuery::defense) sq.result++;
    }
  }
};

class GoblinKing : public Goblin {
 public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) {}

  void query(Creature *creature, StatQuery &sq) override {
    if (creature != this && sq.statistic == StatQuery::attack)
      sq.result++;
    else
      Goblin::query(creature, sq);
  }
};