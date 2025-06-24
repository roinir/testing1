#pragma once

#include "Tuple.h"

template <typename T1, typename T2> class HashTable
{
  public:
    HashTable(int length);

    void addTuple(T1 key, T2 val);
    T2 searchForVal(T1 key) const;
    /*
    void delKey(T1 key);
    int getLength() const;
    T1 searchForKey(T2);
    bool isKeyInTable(T1);

    HashTable operator+(const ComplexNum& other) const;
    HashTable operator+=(const ComplexNum& other) const;
    bool operator==(const String& str1) const;

    ~String();                              // destructor
    String(const String& other);            // copy constructor
    String& operator=(const String& other); // copy assignment operator
    */

  private:
    Tuple<T1, T2>* m_hashTable;
    int m_length;
};