#pragma once

#include "Tuple.h"

class HashTable
{
  public:
    HashTable(int length);

    void addTuple(unsigned char key, unsigned char val);
    unsigned char searchForVal(unsigned char key) const;
    void setLength(int length);
    int hashKey(unsigned char key) const; // using the ptr(this), cast to int and reminder the length of the hash table
                                          // or using
                                 // the /random in linux, can use wsl

    void delKey(unsigned char key);
    int getLength() const;
    unsigned char searchForKey(unsigned char val);
    bool isKeyInTable(unsigned char key);
    Tuple* getTable() const;
    void display() const;


    HashTable operator+(const HashTable& other) const;
    bool operator==(const HashTable& other) const;
    void operator+=(const HashTable& other);


    HashTable& operator=(const HashTable& other); // copy assignment operator
    ~HashTable();                                 // destructor
    HashTable(const HashTable& other);            // copy constructor


  private:
    Tuple* m_hashTable;
    int m_length;

 
};