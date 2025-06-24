/*
    HashTable operator+=(const ComplexNum& other) const;
    bool operator==(const String& str1) const;

    ~String();                              // destructor
    String(const String& other);            // copy constructor
    String& operator=(const String& other); // copy assignment operator
*/

#include <iostream>

#include "HashTable.h"

template <typename T1, typename T2> HashTable<T1, T2>::HashTable(int length)
{
    m_length = length;
}

template <typename T1, typename T2> void HashTable<T1, T2>::addTuple(T1 key, T2 val)
{
    Tuple<T1, T2> newTuple = Tuple<T1, T2>(key, val);
    int indexInTable = hashKey(key);
    m_hashTable[indexInTable] = newTuple;
}

template <typename T1, typename T2> void HashTable<T1, T2>::setLength(int length)
{
    m_length = length;
}

template <typename T1, typename T2> T2 HashTable<T1, T2>::searchForVal(T1 key) const
{
    int index = hashKey(key);
    Tuple<T1, T2> tuple = m_hashTable[index];
    return tuple.getVal();
}

template <typename T1, typename T2> int HashTable<T1, T2>::hashKey(T1 key)
{
    return static_cast<int>(std::hash<key>) % m_length;
}

template <typename T1, typename T2> void HashTable<T1, T2>::delKey(T1 key)
{
    int index = hashKey(key);
    m_hashTable[index] = NULL;
}

template <typename T1, typename T2> int HashTable<T1, T2>::getLength() const
{
    return m_length;
}

template <typename T1, typename T2> T1 HashTable<T1, T2>::searchForKey(T2 val)
{
    Tuple<T1, T2> tempTuple;
    for (int i = 0; i < m_length; i++)
    {
        tempTuple = m_hashTable[i];
        if (tempTuple.getVal() == val)
        {
            return tempTuple.getKey();
        }
    }
    ctd::cout << "Key that holds that value does not exist.";
    return NULL;
}

template <typename T1, typename T2> bool HashTable<T1, T2>::isKeyInTable(T1 key)
{
    int index = hashKey(=key);
    Tuple<T1, T2> tuple = m_hashTable[index];
    return (tuple.getKey() == key);
}

template <typename T1, typename T2> HashTable<T1, T2> HashTable<T1, T2>::operator+(const HashTable<T1, T2>& other) const
{
    HashTable<T1, T2> newTable = HashTable<T1, T2>(m_length + other.m_length);
    int index;
    for (int i = 0; i < m_length; i++)
    {
        index = newTable.hashKey(m_hashTable[i]);
        newTable[index] = m_hashTable[i];
    }
    for (int i = 0; i < other.m_length; i++)
    {
        index = newTable.hashKey(other.m_hashTable[i]);
        newTable[index] = other.m_hashTable[i];
    }
    return newTable;
}
