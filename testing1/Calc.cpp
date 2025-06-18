#include <iostream>

#include "Calc.h"

double Calc::add(const double n1, const double n2)
{
    return n1 + n2;
}

double Calc::multiply(const double n1, const double n2)
{
    return n1 * n2;
}

double Calc::divide(const double n1, const double n2)
{
    if (n2 == 0)
    {
        throw DivisionByZeroException();
    }
    return n1 / n2;
}

double Calc::substract(const double n1, const double n2)
{
    return n1 - n2;
}

double Calc::calculate(const double n1, const char op, const double n2)
{
    switch (op)
    {
    case '+':
        return add(n1, n2);
    case '-':
        return substract(n1, n2);
    case '/':
        return divide(n1, n2);
    case '*':
        return multiply(n1, n2);
    default:
        throw OperatorIsIncorrect();
    }
}