#include "String.h"

String::String(const char* str)
{
    int size = m_getSizeOfConstCharArr(str);
    m_str = new char(size);
    for (int i = 0; i <= size; i++)
    {
        m_str[i] = str[i];
    }
}

String::String(const String& other)
{
    m_str = other.m_str;
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

String String::operator+(const String& other) const
{
    int newSize = this->getSize() + other.getSize();
    char* tempStr = new char(newSize + 1);
    for (int i = 0; i < this->getSize(); i++)
    {
        tempStr[i] = m_str[i];
    }
    for (int i = 0; i < other.getSize(); i++)
    {
        tempStr[this->getSize() + i] = other.m_str[i];
    }
    tempStr[newSize] = '\0';
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

bool String::operator==(const String& other) const
{
    if (this->getSize() != other.getSize())
    {
        return false;
    }
    for (int i = 0; i < this->getSize(); i++)
    {
        if (m_str[i] != other.m_str[i])
        {
            return false;
        }
    }
    return true;
}

String& String::operator=(const String& other)
{
    m_str = other.m_str;
    return *this;
}

String::~String()
{
    delete m_str;
}