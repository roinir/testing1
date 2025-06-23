#include <iostream>

#include "MetaData.h"

MetaData::MetaData()
{
    m_size = 0;
    m_nextMetaData = NULL;
    std::cout << "first ptr in linked list initialize\n";
}

MetaData::MetaData(std::size_t size) : m_size(size)
{
    m_nextMetaData = NULL;
    std::cout << "\nanother ptr in linked list initialized\n";
}

std::size_t MetaData::getSize() const
{
    return m_size;
}

MetaData* MetaData::getNextMetaData() const
{
    return m_nextMetaData;
}

MetaData* MetaData::getLastMetaData(MetaData* temp)
{
    int count = 0;
    while (temp->getNextMetaData())
    {
        count++;
        temp = temp->getNextMetaData();
    }
    std::cout << "\nThe count is: " << count << "\n";
    std::cout << "I am: " << &temp;
    return temp;
}

void MetaData::setNextMetaData(MetaData* nextPtr)
{
    m_nextMetaData = nextPtr;
}