#include <iostream>

using namespace std;

int main()
{
    try
    {
        //MetaData firstPtr = MetaData();
        //MemAlloc* p = new (0) MemAlloc;
        //delete[] ptr;
        int* num = new int(3);
        int* num1 = new int(3);
        int* num2 = new int(3);
        return 0;
    }
    catch (bad_alloc& ba)
    {
        cout << ba.what() << endl;
        return 1;
    }
}