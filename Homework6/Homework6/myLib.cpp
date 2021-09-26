#include <iostream>
#include <fstream>
using namespace std;
namespace myLib
{
    void DinamicArr(int length=10)
    {

        unsigned float* ptr;

        ptr = new (nothrow) unsigned int[length];
        if (ptr != nullptr)
        {
            ptr[0] = 1;
            for (int i = 1; i < length + 1; i++)
                ptr[i] = -20 + rand()%20;


        }
    }

    void PrintArr(int length=10)
    {
        for (int i = 1; i < length + 1; i++)
            cout << ptr[i];
    }

    int Calculation(char plusminus='+')
    {
        int plus = 0, minus = 0;
        for (int i = 1; i < length + 1; i++)
            if (ptr[i] < 0)
                minus++;
            else
                plus++;
        if (plusminus == '-')
            return minus;
            if (plusminus=='+')
                return plus;
    }
}