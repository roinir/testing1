#include "MultTable.h"

#include <iostream>


void printMultTable()
{
    for (int i = 1; i <= BOARD_SIZE; i++)
    {
        for (int j = 1; j <= BOARD_SIZE; j++)
        {
            printSingleNumInTable(i * j);
        }
        std::cout << "\n";
    }
}

void printSingleNumInTable(int num)
{
    if (num >= 100)
    {
        std::cout << " " << num;
    }
    else if (num >= 10)
    {
        std::cout << "  " << num; 
    }
    else
    {
        std::cout << "   " << num;
    }
}