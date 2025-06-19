#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <new>

#include "NewHandler.h"

// no inline, required by [replacement.functions]/3
void* operator new(std::size_t sz)
{
    MetaData metaData = MetaData(sz);
    MetaData* lastMetaData = MetaData::getLastMetaData(&FIRST_PTR);
    lastMetaData->setNextMetaData(&metaData);
    std::printf("1) new(size_t), size = %zu\n", sz);
    if (sz == 0)
        ++sz; // avoid std::malloc(0) which may return nullptr on success

    if (void* ptr = std::malloc(sz))
        return ptr;

    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

// no inline, required by [replacement.functions]/3
void* operator new[](std::size_t sz)
{
    MetaData metaData = MetaData(sz);
    MetaData* lastMetaData = MetaData::getLastMetaData(&FIRST_PTR);
    lastMetaData->setNextMetaData(&metaData);
    std::printf("2) new[](size_t), size = %zu\n", sz);
    if (sz == 0)
        ++sz; // avoid std::malloc(0) which may return nullptr on success

    if (void* ptr = std::malloc(sz))
        return ptr;

    throw std::bad_alloc{}; // required by [new.delete.single]/3
}

void operator delete(void* ptr) noexcept
{
    std::puts("3) delete(void*)");
    std::free(ptr);
}

void operator delete(void* ptr, std::size_t size) noexcept
{
    std::printf("4) delete(void*, size_t), size = %zu\n", size);
    std::free(ptr);
}

void operator delete[](void* ptr) noexcept
{
    std::puts("5) delete[](void* ptr)");
    std::free(ptr);
}

void operator delete[](void* ptr, std::size_t size) noexcept
{
    std::printf("6) delete[](void*, size_t), size = %zu\n", size);
    std::free(ptr);
}
