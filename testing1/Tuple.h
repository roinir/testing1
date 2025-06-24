#pragma once

template <typename T1, typename T2> class Tuple
{
  public:
    Tuple(T1 key, T2 val);
    T1 getKey() const;
    T2 getVal() const;
    void setKey(T1 key);
    void setVal(T2 val);
    int hashKey(int rem); // using the ptr(this), cast to int and reminder the length of the hash table or using the
                          // /random in linux, can use wsl

    ~Tuple();                                             // destructor
    Tuple(const Tuple<T1, T2>& other);                    // copy constructor
    Tuple<T1, T2>& operator=(const Tuple<T1, T2>& other); // copy assignment operator

    bool operator==(const Tuple<T1, T2>& other) const;

  private:
    T1 m_key;
    T2 m_val;
};