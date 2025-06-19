#pragma once

class String
{
  public:
    String(const char* str);
    char* getStr() const;
    int getSize() const;
    void setStr(const char* a, int size);
    /*
    String operator+(const String& other) const;
    */
    /*
    bool operator==(const String& rhs);
    bool operator!=(const String& rhs);
    */

    //~String();
    String m_newStr(char* str1, char* str2);

  private:
    char* m_str;
    //char* m_getSpace(char* str);
    //String m_newStr(char* str1, char* str2);
    int m_getSizeOfConstCharArr(const char* str);
    int m_getSizeOfCharArr(char* str);
};