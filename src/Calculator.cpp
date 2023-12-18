// Calculator.cpp
#include "../include/Calculator.h"
#include <cctype>
#include <cmath>
#include <stdexcept>

Calculator::Calculator() {}

void Calculator::clear() {
    while (!ops.empty()) ops.pop();
    while (!nums.empty()) nums.pop();
}

int Calculator::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double Calculator::applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0)
            throw std::runtime_error("Cannot divide by zero");
        return a / b;
    }
    return 0;
}

double Calculator::calculate(std::string input) {
    clear();

    int i = 0;
    while (i < input.size()) {
        if (std::isspace(input[i])) {
            i++;
            continue;
        }

        if (std::isdigit(input[i]) || input[i] == '.') {
            double num = 0;
            int decimal = 0;
            while (i < input.size() && (std::isdigit(input[i]) || input[i] == '.')) {
                if (input[i] == '.') {
                    decimal = 1;
                } else {
                    num = num * 10 + (input[i] - '0');
                    decimal *= 10;
                }
                i++;
            }
            nums.push(decimal ? num / decimal : num);
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(input[i])) {
                double b = nums.top(); nums.pop();
                double a = nums.top(); nums.pop();
                nums.push(applyOp(a, b, ops.top()));
                ops.pop();
            }
            ops.push(input[i]);
            i++;
        }
    }

    while (!ops.empty()) {
        double b = nums.top(); nums.pop();
        double a = nums.top(); nums.pop();
        nums.push(applyOp(a, b, ops.top()));
        ops.pop();
    }

    return nums.top();
}
