#include "../include/Calculator.h"

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if(b != 0) {
        return a / b;
    } else {
        throw "Division by zero condition!";
    }
}

double Calculator::logarithm(double a) {
    return log(a);
}

double Calculator::squareRoot(double a) {
    return sqrt(a);
}

double Calculator::power(double a, double b) {
    return pow(a, b);
}

double Calculator::sine(double a) {
    return sin(a);
}

double Calculator::cosine(double a) {
    return cos(a);
}
