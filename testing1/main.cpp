#include <iostream>

#include "String.h"


int main()
{
    String str1 = String("hello world!!!");
    String str2 = String("hi hi hi");
    String str3 = String("hello world!!!");
    std::cout << str1.getSize();
    std::cout << "\n" << str1.getStr();
    if (str1 == str2)
    {
        std::cout << "str1 and str2 are equal";
    }
    else
    {
        std::cout << "str1 and str2 are not equal";
    }
    if (str1 == str3)
    {
        std::cout << "str1 and str3 are equal";
    }
    else
    {
        std::cout << "str1 and str3 are not equal";
    }

    return 0;
}