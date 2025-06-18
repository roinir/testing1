#include <iostream>

#include "ComplexNum.h"

int main()
{
    ComplexNum c1;
    ComplexNum c2 = ComplexNum(1, 2);
    ComplexNum c3 = ComplexNum(3, 4);
    c1.printNum();
    c2.printNum();
    c3.printNum();
    (c1 + c2).printNum();
    (c1 + c3).printNum();
    (c2 + c3).printNum();
    (c3 + c2).printNum();
    (c3 + c2).printNum();
    (c3 - c2).printNum();
    (c3 * c2).printNum();
    (c2 + c2 * c3).printNum(); // The order of the operations is kept
    return 0;
}