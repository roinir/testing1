#include <cmath>
#include <iostream>

#include "PrimeNumbers.h"

bool isPrime(int num)
{
    if (num == 1)
    {
        return false;
    }
    else if (num < 1)
    {
        throw error_codes::nonPositiveNumber;
    }
    for (int i = 2; i <= static_cast<int>(sqrt(num)); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void printIsNumberPrime(int num)
{
    try
    {
        if (isPrime(num))
        {
            std::cout << "The number " << num << " is prime ";
        }
        else
        {
            std::cout << "The number " << num << " is not prime ";
        }
    }
    catch (error_codes nonPositiveNumber)
    {
        std::cout << "The number has to be positive!";
    }
}

void fillArr(int* arr, int size)
{
    int i = 2;
    int count = 0;
    while (count < size)
    {
        if (isPrime(i))
        {
            arr[count] = i;
            count++;
        }
        i++;
    }
}