#include <complex>
#include <iostream>
#include <tuple>
#include <vector>

struct DiscriminantStrategy {
  virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy {
  double calculate_discriminant(double a, double b, double c) {
    return (b * b) - (4 * a * c);
  }
};

struct RealDiscriminantStrategy : DiscriminantStrategy {
  double calculate_discriminant(double a, double b, double c) {
    double result = (b * b) - (4 * a * c);
    if (result < 0)
      return NAN;
    else
      return result;
  }
};

class QuadraticEquationSolver {
  DiscriminantStrategy& strategy;

 public:
  QuadraticEquationSolver(DiscriminantStrategy& strategy)
      : strategy(strategy) {}

  std::tuple<std::complex<double>, std::complex<double>> solve(double a,
                                                               double b,
                                                               double c) {
    std::complex<double> discriminant{strategy.calculate_discriminant(a, b, c)};
    return {(-b + std::sqrt(discriminant)) / (2 * a),
            (-b - std::sqrt(discriminant)) / (2 * a)};
  }
};
