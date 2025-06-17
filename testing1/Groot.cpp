#include <cmath>
#include <typeinfo>
#include "Groot.h"
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

void takeInputAndCalc()
{
    float num;
    std::cout << "Input a number: ";
    std::cin >> std::defaultfloat >> num;

    try
    {
        std::cout << "The sqrt of " << num << " is " << calcSqrt(num);
    }
    catch (error_code negativeNumError)
    {
        std::cout << "The number can't be negative!";
    }
}