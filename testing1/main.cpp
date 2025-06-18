#include <iostream>

#include "Calc.h"

int main()
{
    double n1;
    char op;
    double n2;
    std::cout << "Input the first number: ";
    std::cin >> n1;
    std::cout << "Input the operator: ";
    std::cin >> op;
    std::cout << "Input the first number: ";
    std::cin >> n2;

    if (std::cin.fail())
    {
        std::cin.clear(); // Clear the error flag
        std::cout << "Invalid input. Please enter a number.\n";
        return 1;
    }
    std::cout << Calc::calculate(n1, op, n2);
    return 0;
}