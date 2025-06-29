#pragma once

#include "Tuple.h"

template <typename T1, typename T2> class HashTable
{
  public:
    HashTable(int length);

    void addTuple(T1 key, T2 val);
    T2 searchForVal(T1 key) const;
    void setLength(int length);
    int hashKey(T1 key); // using the ptr(this), cast to int and reminder the length of the hash table or using
                                 // the /random in linux, can use wsl

    void delKey(T1 key);
    int getLength() const;
    T1 searchForKey(T2 val);
    bool isKeyInTable(T1 key);


    HashTable<T1, T2> operator+(const HashTable<T1, T2>& other) const;

    /*

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