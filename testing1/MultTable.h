#pragma once

int const BOARD_SIZE = 11;
int const OFFSET_SPACE = 2;

// print multiplication table
void printMultTable();

// helper function to printMultTable
void printSingleNumInTable(int num);

// helper function to: calcNumOfSpaces, calculates the a number used in calculating the number of spaces for a number
int calcOppositeNumOfSpaces(int num);

// helper function to calc number of spaces for the printSingleNumInTable
int calcNumOfSpaces(int num);