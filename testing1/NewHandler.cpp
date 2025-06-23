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
    // std::printf("new(size_t), size = %zu", sz);
    if (sz == 0)
        ++sz; // avoid std::malloc(0) which may return nullptr on success

    if (void* ptr = std::malloc(sz + sizeof(MetaData)))
    {
        addToLinkedList(reinterpret_cast<MetaData*>(ptr), sz);
        printLinkedList();
        MetaData* ptrReturnMeta = reinterpret_cast<MetaData*>(ptr) + 1;
        void* ptrReturnVoid = reinterpret_cast<void*>(ptrReturnMeta);
        return ptrReturnVoid;
    }

    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

// no inline, required by [replacement.functions]/3
void* operator new[](std::size_t sz)
{
    // std::printf("2) new[](size_t), size = %zu\n", sz);
    if (sz == 0)
        ++sz; // avoid std::malloc(0) which may return nullptr on success

    if (void* ptr = std::malloc(sz + sizeof(MetaData)))
    {
        addToLinkedList(reinterpret_cast<MetaData*>(ptr), sz);
        printLinkedList();
        MetaData* ptrReturnMeta = reinterpret_cast<MetaData*>(ptr) + 1;
        void* ptrReturnVoid = reinterpret_cast<void*>(ptrReturnMeta);
        return ptrReturnVoid;
    }

    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

void operator delete(void* ptr) noexcept
{
    // std::puts("3) delete(void*)");
    MetaData* tempPtr = reinterpret_cast<MetaData*>(ptr) - 1;
    std::free(reinterpret_cast<void*>(ptr));
    deleteFromLinkedList(tempPtr);
    printLinkedList();
}


void operator delete(void* ptr, std::size_t size) noexcept
{
    // std::printf("4) delete(void*, size_t), size = %zu\n", size);
    MetaData* tempPtr = reinterpret_cast<MetaData*>(ptr) - 1;
    ptr = malloc(size); // To make sure the ptr is not uninitialized
    std::free(reinterpret_cast<void*>(ptr));
    deleteFromLinkedList(tempPtr);
    printLinkedList();
}


void operator delete[](void* ptr) noexcept
{
    // std::puts("5) delete[](void* ptr)");
    MetaData* tempPtr = reinterpret_cast<MetaData*>(ptr) - 1;
    std::free(reinterpret_cast<void*>(ptr));
    deleteFromLinkedList(tempPtr);
    printLinkedList();
}

void operator delete[](void* ptr, std::size_t size) noexcept
{
    // std::printf("6) delete[](void*, size_t), size = %zu\n", size);
    MetaData* tempPtr = reinterpret_cast<MetaData*>(ptr) - 1;
    ptr = malloc(size);
    std::free(reinterpret_cast<void*>(ptr));
    deleteFromLinkedList(tempPtr);
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
        std::cout << "Mem" << count << " size: " << tempPtr->getSize() << " location: " << tempPtr + 1 << ", ";
    }
}

void deleteFromLinkedList(MetaData* ptr)
{
    MetaData* tempPtr = &FIRST_PTR;

    MetaData* prev = &FIRST_PTR;
    while (tempPtr->getNextMetaData())
    {
        prev = tempPtr;
        tempPtr = tempPtr->getNextMetaData();
        if (tempPtr == ptr)
        {
            break;
        }
    }
    if (tempPtr != &FIRST_PTR)
    {
        prev->setNextMetaData(tempPtr->getNextMetaData());
    }
    std::cout << "\nDeleted allocated data in the following location: " << tempPtr + 1 << "\n";
}

void addToLinkedList(MetaData* ptr, std::size_t sz)
{
    std::construct_at(ptr, sz, reinterpret_cast<MetaData*>(NULL));
    MetaData* lastMetaData = MetaData::getLastMetaData(&FIRST_PTR);
    lastMetaData->setNextMetaData(ptr);
    // std::cout << "\nAllocated data in the following location: " << ptr - sz << "\n";
}