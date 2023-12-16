#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>

class Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double logarithm(double a);
    double squareRoot(double a);
    double power(double a, double b);
    double sine(double a);
    double cosine(double a);
};

#endif // CALCULATOR_H
