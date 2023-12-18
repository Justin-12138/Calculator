// Calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <string>

class Calculator {
public:
    Calculator();
    double calculate(std::string input);
    void clear();

private:
    std::stack<char> ops;
    std::stack<double> nums;

    int precedence(char op);
    double applyOp(double a, double b, char op);
};

#endif // CALCULATOR_H
