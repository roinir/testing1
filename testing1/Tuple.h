#pragma once


class Tuple
{
  public:
    Tuple(unsigned char key, unsigned char val);

    unsigned char getKey() const;
    unsigned char getVal() const;
    void setKey(unsigned char key);
    void setVal(unsigned char val);


    ~Tuple();                                             // destructor
    Tuple(const Tuple& other);                    // copy constructor
    Tuple& operator=(const Tuple& other); // copy assignment operator

    bool operator==(const Tuple& other) const;

  private:
    unsigned char m_key;
    unsigned char m_val;
};