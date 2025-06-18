#include "MultTable.h"

#include <iostream>
#include <string>

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
    int numOfSpaces = calcNumOfSpaces(num);
    std::string result;
    result.append(numOfSpaces, ' '); // contains the string of spaces required
    std::cout << result << num;
}

int calcOppositeNumOfSpaces(int num)
{
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int calcNumOfSpaces(int num)
{
    int opp = calcOppositeNumOfSpaces(num);
    return calcOppositeNumOfSpaces(BOARD_SIZE) - opp + OFFSET_SPACE;
}