#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

struct Token {
  enum Type { var, integer, plus, minus } type;
  std::string text;

  Token(Type type, const std::string &text) : type{type}, text{text} {};

  friend std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << "`" << token.text << "`";
    return os;
  }
};

struct ExpressionProcessor {
  std::map<char, int> variables;

  int calculate(const std::string &expression) {
    std::vector<Token> tokens = lex(expression);
    return parse(tokens);
  }

  int parse(const std::vector<Token> &tokens) {
    int result = 0;
    int value = 0;
    enum BinOp { add, sub, noOp } binOp = noOp;
    for (size_t i = 0; i < tokens.size(); i++) {
      auto &token = tokens[i];
      switch (token.type) {
      case Token::integer: {
        value = std::stoi(token.text);
        if (binOp == add) {
          result += value;
        } else if (binOp == sub) {
          result -= value;
        } else {
          result += value;
        }
        binOp = noOp;
        break;
      }
      case Token::minus:
        binOp = sub;
        break;
      case Token::plus:
        binOp = add;
        break;
      case Token::var: {
        char ch = token.text.front();
        auto it = variables.find(ch);
        if (it != variables.end()) {
          value = it->second;
          if (binOp == add) {
            result += value;
          } else if (binOp == sub) {
            result -= value;
          } else {
            result += value;
          }
          binOp = noOp;
        } else {
          return 0;
        }
        break;
      }
      default:
        break;
      }
    }

    return result;
  }

  std::vector<Token> lex(const std::string &expr) {

    std::vector<Token> result;

    for (size_t i = 0; i < expr.size(); i++) {
      switch (expr[i]) {
      case '+':
        result.push_back(Token{Token::plus, "+"});
        break;
      case '-':
        result.push_back(Token{Token::minus, "-"});
        break;
      default:
        if (isalpha(expr[i])) {
          result.push_back(Token{Token::var, std::string(1, expr[i])});
          break;
        }
        std::ostringstream buffer;
        buffer << expr[i];
        for (int j = i + 1; j < expr.size(); j++) {
          if (!isdigit(expr[j])) {
            break;
          }
          buffer << expr[j];
          i++;
        }
        result.push_back(Token{Token::integer, buffer.str()});
        break;
      }
    }

    return result;
  }
};