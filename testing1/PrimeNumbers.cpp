#include <cmath>
#include <iostream>

bool isPrime(int num)
{
    for (int i = 2; i <= static_cast<int>(sqrt(num)); i++)
    {
        for (int j = pow(i, 2); j <= num; j += i)
        {
            if (num == j)
            {
                return false;
            }
        }
    }
    return true;
}

void printIsNumberPrime(int num)
{
    if (isPrime(num))
    {
        std::cout << "The number is prime";
    }
    else
    {
        std::cout << "The number is not prime";
    }
}

