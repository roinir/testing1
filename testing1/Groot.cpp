#include "Groot.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

float calcSqrt(float num)
{
    if (num < 0)
    {
        throw error_code::negativeNumError;
    }
    return sqrt(num);
}

void takeInputAndCalcSqrt()
{

    std::cout << "Input a number: ";
    float num;
    std::cin >> num;
    if (std::cin.fail())
    {
        std::cin.clear(); // Clear the error flag
        std::cout << "Invalid input. Please enter a number.\n";
        return;
    }

    try
    {
        std::cout << "The sqrt of " << num << " is " << calcSqrt(num) << "\n";
    }
    catch (error_code negativeNumError)
    {
        std::cout << "The number can't be negative!\n";
    }
}