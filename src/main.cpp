#include <iostream>
#include <cstdlib>
#include "../include/Calculator.h"

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <num1> <num2>" << endl;
        return 1;
    }

    Calculator calculator;
    double a = atof(argv[1]);
    double b = atof(argv[2]);

    cout << "Add: " << calculator.add(a, b) << endl;
    cout << "Subtract: " << calculator.subtract(a, b) << endl;
    cout << "Multiply: " << calculator.multiply(a, b) << endl;
    cout << "Divide: " << calculator.divide(a, b) << endl;
    return 0;
}

