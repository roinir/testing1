#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <new>

#include "MetaData.h"

void* operator new(std::size_t sz);

void* operator new[](std::size_t sz);

void operator delete(void* ptr) noexcept;

void operator delete(void* ptr, std::size_t size) noexcept;

void operator delete[](void* ptr) noexcept;

void operator delete[](void* ptr, std::size_t size) noexcept;

void printLinkedList();

MetaData FIRST_PTR = MetaData();
