/*
    HashTable operator+=(const ComplexNum& other) const;
    bool operator==(const String& str1) const;

    ~String();                              // destructor
    String(const String& other);            // copy constructor
    String& operator=(const String& other); // copy assignment operator
*/

#include <iostream>

#include "HashTable.h"


HashTable::HashTable(int length)
{
    m_length = length;
    m_hashTable = new Tuple(NULL, NULL);
    for (int i = 1; i < length; i++)
    {
        m_hashTable[i] = Tuple(NULL, NULL);
    }
}
void HashTable::addTuple(unsigned char key, unsigned char val)
{
    Tuple newTuple(key, val);
    int indexInTable = hashKey(key);
    m_hashTable[indexInTable] = newTuple;
}

void HashTable::setLength(int length)
{
    m_length = length;
}

unsigned char HashTable::searchForVal(unsigned char key) const
{
    int index = hashKey(key);
    Tuple tuple = m_hashTable[index];
    return tuple.getVal();
}

int HashTable::hashKey(unsigned char key) const
{
    return static_cast<int>(std::hash<int>{}(key)) % m_length;
}

void HashTable::delKey(unsigned char key)
{
    int index = hashKey(key);
    m_hashTable[index] = Tuple(NULL, NULL);
}

int HashTable::getLength() const
{
    return m_length;
}

Tuple* HashTable::getTable() const
{
    return m_hashTable;
}

unsigned char HashTable::searchForKey(unsigned char val)
{
    Tuple tempTuple = Tuple(NULL, NULL);
    for (int i = 0; i < m_length; i++)
    {
        tempTuple = m_hashTable[i];
        if (tempTuple.getVal() == val)
        {
            return tempTuple.getKey();
        }
    }
    std::cout << "Key that holds that value does not exist.";
    return NULL;
}

bool HashTable::isKeyInTable(unsigned char key)
{
    int index = hashKey(key);
    Tuple tuple = m_hashTable[index];
    return (tuple.getKey() == key);
}

HashTable HashTable::operator+(const HashTable& other) const
{
    HashTable newTable = HashTable(m_length + other.m_length);
    int index;
    for (int i = 0; i < m_length; i++)
    {
        index = newTable.hashKey(m_hashTable[i].getKey());
        newTable.getTable()[index] = m_hashTable[i];
    }
    for (int i = 0; i < other.m_length; i++)
    {
        index = newTable.hashKey(other.m_hashTable[i].getKey());
        newTable.getTable()[index] = other.m_hashTable[i];
    }
    return newTable;
}

void HashTable::display() const
{
    std::cout << "The list is:";
    for (int i = 0; i < m_length; i++)
    {
        std::cout << "  (" << m_hashTable[i].getKey() << ", " << m_hashTable[i].getVal() << ")";
    }
}

bool HashTable::operator==(const HashTable& other) const
{
    for (int i = 0; i < m_length; i++)
    {
        if (m_hashTable[i].getKey() != other.m_hashTable[i].getKey() ||
            m_hashTable[i].getVal() != other.m_hashTable[i].getVal())
        {
            return false;
        }
    }
    return true;
}

void HashTable::operator+=(const HashTable& other)
{
    HashTable newTable = HashTable(m_length + other.m_length);
    int index;
    for (int i = 0; i < m_length; i++)
    {
        index = newTable.hashKey(m_hashTable[i].getKey());
        newTable.getTable()[index] = m_hashTable[i];
    }
    for (int i = 0; i < other.m_length; i++)
    {
        index = newTable.hashKey(other.m_hashTable[i].getKey());
        newTable.getTable()[index] = other.m_hashTable[i];
    }
    m_length += other.m_length;
    m_hashTable = newTable.getTable();
}

HashTable& HashTable::operator=(const HashTable& other)
{
    if (m_length != other.m_length)
    {
        std::cout << "lengths have to be equal";
    }
    m_hashTable = other.m_hashTable;
    return *this;
}

HashTable::HashTable(const HashTable& other)
{
    m_length = other.m_length;
    m_hashTable = m_hashTable;
}

HashTable::~HashTable()
{
    delete m_hashTable;
    delete &m_length;
}