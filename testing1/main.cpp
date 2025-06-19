#include <iostream>

#include "PrimeNumbers.h"

using namespace std;

int main()
{
    int num;
    std::cout << "Give a number and I will check if it is prime: ";
    std::cin >> num;
    if (std::cin.fail())
    {
        std::cin.clear(); // Clear the error flag
        std::cout << "Invalid input. Please enter a number.\n";
        return 1;
    }
    int* arr = new int(num);
    fillArr(arr, num);
    for (int i = 0; i < num; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}