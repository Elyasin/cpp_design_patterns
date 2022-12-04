#include <sstream>
#include <string>

struct Expression;
struct AdditionExpression;
struct MultiplicationExpression;
struct Value;

struct ExpressionVisitor {
  virtual void accept(AdditionExpression &addExpr) = 0;
  virtual void accept(MultiplicationExpression &multiExpr) = 0;
  virtual void accept(Value &value) = 0;
};

struct Expression {
  virtual void visit(ExpressionVisitor &ev) = 0;
};

struct Value : Expression {
  int value;

  Value(int value) : value(value) {}

  void visit(ExpressionVisitor &ev) { ev.accept(*this); }
};

struct AdditionExpression : Expression {
  Expression &lhs, &rhs;

  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}

  void visit(ExpressionVisitor &ev) { ev.accept(*this); }
};

struct MultiplicationExpression : Expression {
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression &lhs, Expression &rhs)
      : lhs(lhs), rhs(rhs) {}

  void visit(ExpressionVisitor &ev) { ev.accept(*this); }
};

struct ExpressionPrinter : ExpressionVisitor {
  void accept(Expression &expr) { expr.visit(*this); }
  void accept(Value &value) { oss << value.value; }

  void accept(AdditionExpression &addExpr) {
    oss << "(";
    addExpr.lhs.visit(*this);
    oss << "+";
    addExpr.rhs.visit(*this);
    oss << ")";
  }

  void accept(MultiplicationExpression &multiExpr) {
    multiExpr.lhs.visit(*this);
    oss << "*";
    multiExpr.rhs.visit(*this);
  }

  std::string str() const { return oss.str(); }

 private:
  std::ostringstream oss{};
};