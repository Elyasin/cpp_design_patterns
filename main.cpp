#include <iostream>

// #include "./exercise1/code_builder.cpp"
// #include "./exercise2/factory.cpp"
// #include "./exercise3/prototype.cpp"
// #include "./exercise5/adapter.cpp"
// #include "./exercise6/bridge.cpp"
// #include "./exercise7/composite.cpp"
// #include "./exercise8/decorator_dynamic.cpp"
// #include "./exercise8/decorator_static.cpp"
// #include "./exercise9/flyweight.cpp"
// #include "./exercise10/proxy.cpp"
// #include "./exercise11/chain_of_responsibility.cpp"
#include "./exercise12/command.cpp"

int main() {
  // Exercise 1
  // auto cb = CodeBuilder{"Person"}.add_field("name",
  // "string").add_field("age", "int"); std::cout << cb;

  // Exercise 2
  // PersonFactory factory;
  // auto p = factory.create_person("Ely");
  // std::cout << "id: " << p.id << ", name: " << p.name << std::endl;
  // p = factory.create_person("Nur");
  // std::cout << "id: " << p.id << ", name: " << p.name << std::endl;

  // Exercise 3
  // Line line1{new Point{1, 2}, new Point{3, 4}};
  // Line line2 = line1.deep_copy();
  // line2.start->x = 5;
  // line2.start->y = 6;
  // line2.end->x = 7;
  // line2.end->y = 8;
  // std::cout << "(" << line1.start->x << "," << line1.start->y << ")"
  //           << " - "
  //           << "(" << line1.end->x << "," << line1.end->y << ")" << endl;
  // std::cout << "(" << line2.start->x << "," << line2.start->y << ")"
  //           << " - "
  //           << "(" << line2.end->x << "," << line2.end->y << ")" << endl;

  // Exercise 4

  // Exercise 5
  // Square square(5);
  // SquareToRectangleAdapter adapter{square};
  // std::cout << adapter.width() << " * " << adapter.height() << " = "
  //           << adapter.area() << std::endl;

  // Exercise 6
  // RasterRenderer rastRend;
  // std::cout << Triangle(rastRend).str() << std::endl;
  // std::cout << Square(rastRend).str() << std::endl;
  // VectorRenderer vecRend;
  // std::cout << Triangle(vecRend).str() << std::endl;
  // std::cout << Square(vecRend).str() << std::endl;

  // Exercise 7
  // SingleValue single_value{1};
  // ManyValues other_values;
  // other_values.add(2);
  // other_values.add(3);
  // std::cout << sum({&single_value, &other_values}) << std::endl;

  // Exercise 8 (dynamic)
  // Rose rose;
  // RedFlower red_rose{rose};
  // RedFlower red_red_rose{red_rose};
  // BlueFlower blue_red_rose{red_rose};
  // RedFlower red_blue_red_rose{blue_red_rose};
  // std::cout << rose.str() << std::endl;
  // std::cout << red_rose.str() << std::endl;
  // std::cout << red_red_rose.str() << std::endl;
  // std::cout << blue_red_rose.str() << std::endl;
  // std::cout << red_blue_red_rose.str() << std::endl;

  // Exercise 8 (static)
  // Rose rose;
  // RedFlower<Rose> red_rose{rose};
  // RedFlower<RedFlower<Rose>> red_red_rose{red_rose};
  // BlueFlower<RedFlower<Rose>> blue_red_rose{red_rose};
  // RedFlower<BlueFlower<RedFlower<Rose>>> red_blue_red_rose{blue_red_rose};
  // std::cout << rose.str() << std::endl;
  // std::cout << red_rose.str() << std::endl;
  // std::cout << red_red_rose.str() << std::endl;
  // std::cout << blue_red_rose.str() << std::endl;
  // std::cout << red_blue_red_rose.str() << std::endl;

  // Exercise 9
  // Sentence sentence ("hello world");
  // sentence[1].capitalize = true;
  // std::cout << sentence.str() << std::endl;

  // Exercise 10
  // Person person{15};
  // std::cout << person.drink() << std::endl;
  // std::cout << person.drive() << std::endl;
  // std::cout << person.drink_and_drive() << std::endl;
  // ResponsiblePerson responsiblePerson{person};
  // std::cout << responsiblePerson.drink() << std::endl;
  // std::cout << responsiblePerson.drive() << std::endl;
  // std::cout << responsiblePerson.drink_and_drive() << std::endl;
  // responsiblePerson.set_age(17);
  // std::cout << responsiblePerson.drink() << std::endl;
  // std::cout << responsiblePerson.drive() << std::endl;
  // std::cout << responsiblePerson.drink_and_drive() << std::endl;
  // responsiblePerson.set_age(18);
  // std::cout << responsiblePerson.drink() << std::endl;
  // std::cout << responsiblePerson.drive() << std::endl;
  // std::cout << responsiblePerson.drink_and_drive() << std::endl;

  // Exercise 11
  // Game game;
  // Goblin goblin{game};
  // Goblin goblin2{game};
  // Goblin goblin3{game};
  // GoblinKing goblinKing{game};
  // game.creatures.push_back(&goblin);
  // game.creatures.push_back(&goblin2);
  // game.creatures.push_back(&goblin3);
  // game.creatures.push_back(&goblinKing);
  // std::cout << goblin.get_attack() << std::endl;
  // std::cout << goblin.get_defense() << std::endl;
  // std::cout << goblin2.get_attack() << std::endl;
  // std::cout << goblin2.get_defense() << std::endl;
  // std::cout << goblin3.get_attack() << std::endl;
  // std::cout << goblin3.get_defense() << std::endl;
  // std::cout << goblinKing.get_attack() << std::endl;
  // std::cout << goblinKing.get_defense() << std::endl;

  // Exercise 12
  // auto print = [&](Command cmd, Account acc) -> void {
  //   if (cmd.success == true)
  //     std::cout << "Account processed successfully" << std::endl;
  //   else
  //     std::cout << "Account could not be processed successfully" <<
  //     std::endl;
  //   std::cout << "Account balance: " << acc.balance << std::endl;
  // };
  // Account account;
  // Command cmd{Command::Action::withdraw, 50, false};
  // account.process(cmd);
  // print(cmd, account);
  // cmd.action = Command::Action::deposit;
  // cmd.amount = 50;
  // cmd.success = false;
  // account.process(cmd);
  // print(cmd, account);
  // cmd.action = Command::Action::withdraw;
  // cmd.amount = 50;
  // cmd.success = false;
  // account.process(cmd);
  // print(cmd, account);

  // Exercise 13

  return 0;
}