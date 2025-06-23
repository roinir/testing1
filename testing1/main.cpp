#include <iostream>


int main()
{
    try
    {
        //MetaData firstPtr = MetaData();
        //MemAlloc* p = new (0) MemAlloc;
        //delete[] ptr;
        int* num = new int(1);
        std::cout << "\nThe number is: " << *num << "\n";
        delete num;
        int* num1 = new int(3);
        std::cout << "\nThe number is: " << *num1 << "\n";
        int* num2 = new int(3);
        std::cout << "\nThe number is: " << *num2 << "\n";
       

        return 0;
    }
    catch (std::bad_alloc& ba)
    {
        std::cout << ba.what() << std::endl;
        return 1;
    }
}