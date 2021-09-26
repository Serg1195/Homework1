﻿/*
1) Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) 
во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), 
печати его на экран и подсчета количества отрицательных и положительных элементов. 
Вызывайте эти 3-и функции из main для работы с массивом.
2) Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) 
в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, 
вывести на экран «true» или «false».
3) Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. 
Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). 
Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
4) * Объявить структуру Сотрудник с различными полями. 
Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. 
Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. 
Сохраните эту структуру в текстовый файл.
5)* Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).*/

#include <iostream>
#include <fstream>
#include "myLib.h"

int main()
{
	MyLib:: DinamicArr();
	MyLib::PrintArr();
	std::cout << "positive values - " << MyLib:: Calculation() << std::endl;
	std::cout << "negative values - " << MyLib::Calculation('+') << std::endl;
}
