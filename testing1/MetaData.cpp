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
    std::cout << "another ptr in linked list initialized\n";
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
        std::cout << "\nThe count is: " << count << "\n";
        count++;
        temp = temp->getNextMetaData();
    }
    return temp;
}

void MetaData::setNextMetaData(MetaData* nextPtr)
{
    m_nextMetaData = nextPtr;
}
/*
int MetaData::printAllMetaData(MetaData* firstPtr)
{
    MetaData* tempPtr = firstPtr;
    int count = 0;
    while (tempPtr->getNextMetaData())
    {
        count++;
    }
    return count;
}
*/