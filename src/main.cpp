#include <iostream>
#include "../include/Calculator.h"

using namespace std;


int main(){
    Calculator calculator;
    double a = 10.0;
    double b = 2.0;

    cout << "Add: " << calculator.add(a, b) << endl;
    cout << "Subtract: " << calculator.subtract(a, b) << endl;
    cout << "Multiply: " << calculator.multiply(a, b) << endl;
    cout << "Divide: " << calculator.divide(a, b) << endl;
    cout << "Logarithm: " << calculator.logarithm(a) << endl;
    cout << "Square root: " << calculator.squareRoot(a) << endl;
    cout << "Power: " << calculator.power(a, b) << endl;
    cout << "Sine: " << calculator.sine(a) << endl;
    cout << "Cosine: " << calculator.cosine(a) << endl;
    return 0;
}
