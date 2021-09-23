/*1/Выделить в памяти динамический одномерный массив типа int.
Размер массива запросить у пользователя.Инициализировать его числами степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 … 
Вывести массив на экран.Не забыть освободить память. 
= ) Разбить программу на функции.

2/Динамически выделить матрицу 4х4 типа int.Инициализировать ее псевдослучайными числами через функцию rand.
Вывести на экран.Разбейте вашу программу на функции которые вызываются из main.

3/Написать программу, которая создаст два текстовых файла(*.txt), 
примерно по 50 - 100 символов в каждом(особого значения не имеет с каким именно содержимым).
Имена файлов запросить у польлзователя.

4/* Написать функцию, «склеивающую» эти файлы в третий текстовый файл(имя файлов спросить у пользователя).

5/* Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово 
в указанном пользователем файле(для простоты работаем только с латиницей).
Используем функцию find которая есть в строках std::string.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void DinamicArr()
{
    int length;
    unsigned int* ptr;
    cout << "enter the length of the array - ";
    cin >> length;
    ptr = new (nothrow) unsigned int[length];
    if (ptr != nullptr)
    {
        ptr[0] = 1;
        for (int i = 1; i < length + 1; i++)
        {
            ptr[i] = ptr[i - 1] * 2;
            cout << ptr[i - 1] << " ";
        }
        delete[] ptr;
        cout << endl;
    }
}

void DinamicMatrix()
{
    int length=4;
    int* ptr;
    length = length * length;
    ptr = new (nothrow) int[length];
    if (ptr != nullptr)
    {
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            
            ptr[i] = 1 + rand() % 100;

            cout << ptr[i] << "\t";
            j++;
            if (j == sqrt(length))
            {
                cout << "\n";
                j = 0;
            }
            
        }
        delete[] ptr;
    }
}

void CreateFiles()
{
    string FirstFile, SecondFile;
    cout << "Enter the name of the first file - ";
    cin >> FirstFile;
    cout << "Enter the name of the second file - ";
    cin >> SecondFile;
    ofstream first(FirstFile);
    first << "This is the first file created in the 'Homework5' program for the third task";
    ofstream second(SecondFile);
    second << "This is the first second created in the 'Homework5' program for the third task";
    first.close();
    second.close();
}

void MergeFiles()
{
  /*  string FirstFile, SecondFile, ThirdFile, Strfirst, Strsecond;
    cout << "Enter the name of the first file - ";
    cin >> FirstFile;
    cout << "Enter the name of the second file - ";
    cin >> SecondFile;
    cout << "Enter the name of the third file - ";
    cin >> ThirdFile;
    ofstream first(FirstFile);
    while (first) {
        Strfirst= first;
    }
    ofstream second(SecondFile);
    ofstream third(ThirdFile,ios_base::app);
    third << "Merge\n" <<  first << "\n" << second;
    first.close();
    second.close();
    third.close();*/
}

int main()
{
  //Task1
    DinamicArr();
    system("pause");
    //Task2
    DinamicMatrix();
    system("pause");
    //Task3
    CreateFiles();
    system("pause");
    //Task4
 //   MergeFiles();
}
