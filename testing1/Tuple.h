#pragma once

template <typename T1, typename T2> 
class Tuple
{
  public:
    Tuple(T1 key, T2 val);
    T1 getKey() const;
    T2 getVal() const;
    void setKey(T1 a);
    void setVal(T2 b);
    int hashKey(); // using the ptr(this), cast to int and reminder the length of the hash table or using the /random in
                   // linux, can use wsl

    bool HashTable == (const String& str1) const;

    ~String();                              // destructor
    String(const String& other);            // copy constructor
    String& operator=(const String& other); // copy assignment operator

  private:
    T1 key;
    T2 val;
};