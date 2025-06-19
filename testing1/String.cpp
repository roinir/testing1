#include "String.h"

String::String(const char* str)
{
    int size = m_getSizeOfConstCharArr(str);
    m_str = new char(size);
    for (int i = 0; i < size; i++)
    {
        m_str[i] = str[i];
    }
}

char* String::getStr() const
{
    return m_str;
}

int String::getSize() const
{
    int i = 0;
    char ch = *(m_str + i);
    while (ch != '\0')
    {
        i++;
        ch = *(m_str + i);
    }
    return i;
}

void String::setStr(const char* str, int size)
{
    m_str = new char(size);
}

/*
String String::operator+(const String& other) const
{
    return m_newStr(m_str, other.m_str);
}
*/

String String::m_newStr(char* str1, char* str2)
{
    int newSize = m_getSizeOfCharArr(str1) + m_getSizeOfCharArr(str2);
    char* tempStr = new char(newSize);
    for (int i = 0; i < sizeof(str1); i++)
    {
        tempStr[i] = str1[i];
    }
    for (int i = 0; i < sizeof(str2); i++)
    {
        tempStr[sizeof(str1) + i] = str2[i];
    }
    return String(tempStr);
}

int String::m_getSizeOfConstCharArr(const char* str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

int String::m_getSizeOfCharArr(char* str)
{
    int i = 1;
    char ch = *(str + i);
    while (ch != '\0')
    {
        i++;
        ch = *(str + i);
    }
    return i - 1;
}


bool operator==(const String& str1, const String& str2)
{
    if (str1.getSize() != str2.getSize())
    {
        return false;
    }
    for (int i = 0; i < str1.getSize(); i++)
    {
        if (str1.getStr()[i] != str2.getStr()[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const String& str1, const String& str2)
{
    if (str1.getSize() != str2.getSize())
    {
        return true;
    }
    for (int i = 0; i < str1.getSize(); i++)
    {
        if (str1.getStr()[i] != str2.getStr()[i])
        {
            return true;
        }
    }
    return false;
}