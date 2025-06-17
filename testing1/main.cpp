#include "Groot.h"

#include <iostream>


int main()
{
    float num;
    std::cout << "Input a number: ";
    std::cin >> num;
    std::cout << "The sqrt of " << num << " is " << calcSqrt(num);
}
