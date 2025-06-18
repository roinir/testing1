#pragma once

// used for preforming a mathmatical calculation for two nums
class Calc
{
  public:
    static double add(const double n1, const double n2);
    static double divide(const double n1, const double n2);
    static double multiply(const double n1, const double n2);
    static double substract(const double n1, const double n2);
    static double calculate(const double n1, const char op, const double n2);
};

// custom exception for when the operator is not supported by the calc class
class OperatorIsIncorrect
{
};

// custom exception used for when trying to divide by zero
class DivisionByZeroException
{
};