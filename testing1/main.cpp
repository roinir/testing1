#include "PrimeNumbers.h"

#include <iostream>

int main()
{
    int num;
    std::cout << "Give a number and I will check if it is prime: ";
    std::cin >> num;
    printIsNumberPrime(num);
    return 0;
}