#include <iostream>

#include "MetaData.h"

MetaData::MetaData()
{
    m_size = 0;
    m_nextMetaData = NULL;
}

MetaData::MetaData(std::size_t size) : m_size(size)
{
    m_nextMetaData = NULL;
}

MetaData::MetaData(std::size_t size, MetaData* nextMetaData) : m_size(size), m_nextMetaData(nextMetaData)
{
    // left blank intentionally
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
    while (temp->getNextMetaData())
    {
        temp = temp->getNextMetaData();
    }
    return temp;
}

void MetaData::setNextMetaData(MetaData* nextPtr)
{
    m_nextMetaData = nextPtr;
}