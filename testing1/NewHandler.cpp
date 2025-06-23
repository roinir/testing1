#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <new>

#include <bit>
#include <memory>

#include "NewHandler.h"
// no inline, required by [replacement.functions]/3
void* operator new(std::size_t sz)
{
    //std::printf("new(size_t), size = %zu", sz);
    if (sz == 0)
        ++sz; // avoid std::malloc(0) which may return nullptr on success

    if (void* ptr = std::malloc(sz + sizeof(MetaData)))
    {
        addToLinkedList(reinterpret_cast<MetaData*>(ptr) + sz, sz);
        printLinkedList();
        return ptr;
    }


    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

// no inline, required by [replacement.functions]/3
void* operator new[](std::size_t sz)
{
    //std::printf("2) new[](size_t), size = %zu\n", sz);
    if (sz == 0)
        ++sz; // avoid std::malloc(0) which may return nullptr on success

    if (void* ptr = std::malloc(sz))
    {
        addToLinkedList(reinterpret_cast<MetaData*>(ptr) + sz, sz);
        printLinkedList();
        return ptr;
    }


    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

void operator delete(void* ptr) noexcept
{
    //std::puts("3) delete(void*)");
    std::free(ptr);
    deleteFromLinkedList(reinterpret_cast<MetaData*>(ptr));
    printLinkedList();
}

void operator delete(void* ptr, std::size_t size) noexcept
{
    //std::printf("4) delete(void*, size_t), size = %zu\n", size);
    std::free(ptr);
    deleteFromLinkedList(reinterpret_cast<MetaData*>(ptr));
    printLinkedList();
}

void operator delete[](void* ptr) noexcept
{
    //std::puts("5) delete[](void* ptr)");
    std::free(ptr);
    deleteFromLinkedList(reinterpret_cast<MetaData*>(ptr));
    printLinkedList();
}

void operator delete[](void* ptr, std::size_t size) noexcept
{
    //std::printf("6) delete[](void*, size_t), size = %zu\n", size);
    std::free(ptr);
    deleteFromLinkedList(reinterpret_cast<MetaData*>(ptr));
    printLinkedList();
}


void printLinkedList()
{
    std::cout << "\n\nPrinting all memory allocations used in the program: ";
    MetaData* tempPtr = &FIRST_PTR;
    int count = 0;
    while (tempPtr->getNextMetaData())
    {
        count++;
        tempPtr = tempPtr->getNextMetaData();
        std::cout << "Mem" << count << " size: " << tempPtr->getSize() << " location: " << tempPtr - tempPtr->getSize()
                  << ", ";
    }
}

void deleteFromLinkedList(MetaData* ptr)
{
    MetaData* tempPtr = &FIRST_PTR;
    int count = 0;
    int min = LARGE_NUM_FOR_DIFFERENCE;
    MetaData* diffPtr = &FIRST_PTR;
    MetaData* prev = &FIRST_PTR;
    MetaData* maxPrev = &FIRST_PTR;
    while (tempPtr->getNextMetaData())
    {
        count++;
        prev = tempPtr;
        tempPtr = tempPtr->getNextMetaData();
        if ((tempPtr - ptr) < min)
        {
            maxPrev = prev;
            min = tempPtr - ptr;
            diffPtr = tempPtr;
        }
    }
    if (diffPtr != &FIRST_PTR)
    {
        maxPrev->setNextMetaData(diffPtr->getNextMetaData());
    }
    std::cout << "\nDeleted allocated data in the following location: " << diffPtr << "\n";
}

void addToLinkedList(MetaData* ptr, std::size_t sz)
{
    std::construct_at(ptr, sz, reinterpret_cast<MetaData*>(NULL));
    MetaData* lastMetaData = MetaData::getLastMetaData(&FIRST_PTR);
    lastMetaData->setNextMetaData(ptr);
    std::cout << "\nAllocated data in the following location: " << ptr - sz << "\n";
}