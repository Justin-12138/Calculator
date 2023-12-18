// main.cpp
#include "../include/Calculator.h"
#include <iostream>

int main() {
    Calculator calc;
    std::string input;

    while (std::getline(std::cin, input)) {
        if (input == "q") break;

        try {
            std::cout << calc.calculate(input) << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
