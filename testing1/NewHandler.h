#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <new>

#include "MetaData.h"

void printLinkedList();

MetaData FIRST_PTR = MetaData();

const int LARGE_NUM_FOR_DIFFERENCE = 10000;

void addToLinkedList(MetaData* ptr, std::size_t sz);

void deleteFromLinkedList(MetaData* ptr);