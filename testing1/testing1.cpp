// testing1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Defining function that prints given number
void printNum(int n)
{
    std::cout << n;
}

int main()
{
    int num1 = 10;
    int num2 = 99;

    // Calling printNum and passing both
    // num1 and num2 to it one by one
    printNum(num1);
    printNum(num2);
    return 0;
}
