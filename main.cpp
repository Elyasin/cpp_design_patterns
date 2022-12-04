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
// #include "./exercise12/command.cpp"
// #include "./exercise13/interpreter.cpp"
// #include "./exercise14/iterator.cpp"
// #include "./exercise15/mediator.cpp"
// #include "./exercise16/memento.cpp"
// #include "./exercise17/observer.cpp"
// #include "./exercise18/state.cpp"
// #include "./exercise19/strategy.cpp"
// #include "./exercise20/template_method.cpp"
#include "./exercise21/visitor.cpp"

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
  // RasterRenderer rasterRend;
  // std::cout << Triangle(rasterRend).str() << std::endl;
  // std::cout << Square(rasterRend).str() << std::endl;
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
  // ExpressionProcessor proc;
  // std::cout << proc.calculate("1") << std::endl;
  // std::cout << proc.calculate("1+2+3") << std::endl;
  // std::cout << proc.calculate("1+2+xy") << std::endl;
  // proc.variables['x'] = 3;
  // std::cout << proc.calculate("10-2-x") << std::endl;

  // Exercise 14
  // node<char> e('e');
  // node<char> d('d');
  // node<char> c('c', &d, &e);
  // node<char> b('b');
  // node<char> a('a', &b, &c);
  // std::vector<node<char> *> result;
  // a.preorder_traversal(result);
  // for (node<char> *n : result)
  //   std::cout << n->value << ", ";
  // std::cout << std::endl;

  // Exercise 15
  // Mediator mediator;
  // Participant participant1{mediator};
  // Participant participant2{mediator};
  // Participant participant3{mediator};
  // participant1.say(3);
  // participant2.say(2);
  // participant3.say(4);
  // participant1.print();
  // participant2.print();
  // participant3.print();

  // Exercise 16
  // TokenMachine tm;
  // auto token = std::make_shared<Token>(111);
  // tm.add_token(token);
  // auto m = tm.add_token(222);
  // token->value = 333;
  // std::cout << "Before applying memento" << std::endl;
  // for (auto &&token : tm.tokens) {
  //   std::cout << token->value << ", ";
  // }
  // tm.revert(m);
  // std::cout << std::endl << "After applying memento" << std::endl;
  // for (auto &&token : tm.tokens) {
  //   std::cout << token->value << ", ";
  // }

  // Exercise 17
  // Game game;
  // Rat rat1{game};
  // std::cout << "One rat in the game. Attack of rat1 = " << rat1.attack
  //           << std::endl;
  // Rat rat2{game};
  // std::cout << "Two rats in the game. Attack of rat1 = " << rat1.attack
  //           << std::endl;
  // Rat rat3{game};
  // std::cout << "Three rats in the game. Attack of rat1 = " << rat1.attack
  //           << std::endl;

  // Exercise 18
  // CombinationLock cl1({1, 2, 3});
  // cl1.enter_digit(1);
  // cl1.enter_digit(2);
  // cl1.enter_digit(3);
  // std::cout << cl1.status << std::endl;
  // CombinationLock cl2({3, 2, 1});
  // cl2.enter_digit(3);
  // cl2.enter_digit(2);
  // cl2.enter_digit(3);
  // std::cout << cl2.status << std::endl;

  // Exercise 19
  // OrdinaryDiscriminantStrategy ordinaryDiscriminant;
  // QuadraticEquationSolver solver1{ordinaryDiscriminant};
  // auto res1 = solver1.solve(1, 2, 3);
  // std::cout << "Ordinary: (" << std::get<0>(res1) << ", " <<
  // std::get<1>(res1)
  //           << ")" << std::endl;
  // RealDiscriminantStrategy realDiscriminant;
  // QuadraticEquationSolver solver2{realDiscriminant};
  // auto res2 = solver2.solve(1, 2, 3);
  // std::cout << "Real Discriminant: (" << std::get<0>(res2) << ", "
  //           << std::get<1>(res2) << ")" << std::endl;

  // Exercise 20
  // Creature creature1{1, 1};
  // Creature creature2{1, 2};
  // TemporaryCardDamageGame temp{{creature1, creature1}};
  // int result = temp.combat(0, 1);
  // std::cout << "Winner is: " << result << std::endl;
  // Creature creature3{1, 1};
  // Creature creature4{1, 2};
  // PermanentCardDamageGame perm{{creature3, creature4}};
  // result = perm.combat(0, 1);
  // std::cout << "Winner is: " << result << std::endl;

  // Exercise 21
  Value value1{1};
  Value value2{2};
  Value value3{3};
  MultiplicationExpression multiExpr{value2, value3};
  AdditionExpression addExpr{value1, multiExpr};
  ExpressionPrinter ep;
  addExpr.visit(ep);
  std::cout << ep.str() << std::endl;

  return 0;
}