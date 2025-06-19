#include <iostream>

#include "String.h"

int main()
{
    String str1 = String("hi1");
    String str2 = String("hi1");
    String str3 = String("hello world!!!");

    std::cout << str1.getSize();
    std::cout << "\n" << str1.getStr() << "\n";
    std::cout << str2.getSize();
    std::cout << "\n" << str2.getStr() << "\n";
    std::cout << str3.getSize();
    std::cout << "\n" << str3.getStr() << "\n";

    if (str1 == str2)
    {
        std::cout << "str1 and str2 are equal\n";
    }
    else
    {
        std::cout << "str1 and str2 are not equal\n";
    }
    if (str1 == str3)
    {
        std::cout << "str1 and str3 are equal\n";
    }
    else
    {
        std::cout << "str1 and str3 are not equal\n";
    }

    String newStr = str1 + str3;
    std::cout << newStr.getStr() << " ";
    std::cout << newStr.getSize();

    return 0;
}