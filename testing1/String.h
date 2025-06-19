#pragma once

class String
{
  public:
    String(const char* str);
    char* getStr() const;
    int getSize() const;
    void setStr(const char* a, int size);
    String operator+(const String& other) const;
    bool operator==(const String& str1) const;
    ~String();                              // destructor
    String(const String& other);            // copy constructor
    String& operator=(const String& other); // copy assignment operator

  private:
    char* m_str;
    int m_getSizeOfConstCharArr(const char* str);
};