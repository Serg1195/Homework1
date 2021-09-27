#include <iostream>
#include <fstream>




namespace myLib
{
    float* DinamicArr(int length = 19)
    {
        float* ptr = new (std::nothrow) float[length];
        if (ptr != nullptr)
        {
            int j = 0;
            for (int i = 0; i < length; i++)
            {

                ptr[i] = (float)-5 + std::rand() % 10;

                // std::cout << ptr[i] << "\t";
            }
        }
        return ptr;
    }

    void printArr(float* ptr, int length = 19) {
        for (int i = 0; i < length; ++i)
            std::cout << " " << ptr[i];
        std::cout << std::endl;
    }

    int Calculation(float* ptr, char plusminus = '+', int length = 19)
    {
        int plus = 0, minus = 0;
        for (int i = 1; i < length + 1; i++)
            if (ptr[i] < 0)
                minus++;
            else
                plus++;
        if (plusminus == '-')
            return minus;
        else if (plusminus == '+')
            return plus;
        else
            return -1;
    }
}