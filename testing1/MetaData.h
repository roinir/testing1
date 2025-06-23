#pragma once

#include <iostream>

class MetaData
{
  public:
    MetaData();
    MetaData(std::size_t size);
    std::size_t getSize() const;
    MetaData* getNextMetaData() const;
    void setNextMetaData(MetaData* nextPtr);
    static MetaData* getLastMetaData(MetaData* temp);
    //create a static var that counts how many times it was iniziallized

  private:
    std::size_t m_size;
    MetaData* m_nextMetaData;
};



//TODO don't forget to check if a malloc is needed when creating new MetaData objects
//TODO need to figure out how to delete objects from the linked list - for delete