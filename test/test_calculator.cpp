#include <gtest/gtest.h>
#include "../include/Calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

TEST_F(CalculatorTest, BasicOperations) {
    EXPECT_DOUBLE_EQ(calc.calculate("2+2"), 4.0);
    EXPECT_DOUBLE_EQ(calc.calculate("5-3"), 2.0);
    EXPECT_DOUBLE_EQ(calc.calculate("4*3"), 12.0);
    EXPECT_DOUBLE_EQ(calc.calculate("10/2"), 5.0);
}

TEST_F(CalculatorTest, ComplexExpressions) {
    EXPECT_DOUBLE_EQ(calc.calculate("2+3*4"), 14.0);
    EXPECT_DOUBLE_EQ(calc.calculate("(2+3)*4"), 20.0);
    EXPECT_DOUBLE_EQ(calc.calculate("10.5 + 2.3 * (4.1 - 1.2)"), 17.17);
}

TEST_F(CalculatorTest, DivisionByZero) {
    EXPECT_THROW(calc.calculate("10/0"), std::runtime_error);
}

TEST_F(CalculatorTest, InvalidExpressions) {
    EXPECT_THROW(calc.calculate("2++3"), std::runtime_error);
    EXPECT_THROW(calc.calculate("abc"), std::runtime_error);
    EXPECT_THROW(calc.calculate(""), std::runtime_error);
}