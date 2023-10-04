#include <stdlib.h>
#include <iostream>

// Объявление структуры TwoInts
struct TwoInts
{
    int a;
    int b;
};

// Объявление структуры StructWithArray
struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // Создание экземпляра структуры TwoInts с именем i2 и инициализация его полей значениями по умолчанию (0)
    TwoInts i2 = { };
    
    // Присвоение значения 5 полю a структуры i2
    i2.a = 5;

    i2.b = 7;

    // Вывод значений полей a и b на экран
    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;
    
    // Создание экземпляра структуры StructWithArray с именем s и инициализация его полей значениями по умолчанию (0)
    StructWithArray s = { };

    // Присвоение значения 10 первому элементу массива arr структуры s
    s.arr[0] = 10;

    StructWithArray s1 = { };

    s1.arr[0] = 15;

    StructWithArray* sPointer = &s;

    // Присвоение значения 20 первому элементу массива arr через указатель sPointer
    sPointer->arr[0] = 20;

    std::cout << s.arr[0] << std::endl;

    s.arr[0] = 25;

    // Вывод значения первого элемента массива arr структуры s на экран
    std::cout << s.arr[0] << std::endl;

    // Изменение значения первого элемента массива arr структуры s через указатель sPointer
    sPointer->arr[0] = 30;

    std::cout << s.arr[0] << std::endl;

    // Изменение указателя sPointer так, чтобы он указывал на структуру s1
    sPointer = &s1;

    // Изменение значения первого элемента массива arr структуры s через указатель sPointer
    sPointer->arr[0] = 35;

    std::cout << s.arr[0] << std::endl;

    std::cout << s1.arr[0] << std::endl;

    // Создание массива из двух экземпляров структуры StructWithArray и инициализация их значениями по умолчанию (0)
    StructWithArray structArray[2] = { };

    // Присвоение значения 77 четвёртому элементу массива arr первого экземпляра структуры structArray
    structArray[0].arr[3] = 77;

    // Присвоение указателю someNumber второго экземпляра структуры structArray адреса четвёртого элемента массива arr первого экземпляра
    structArray[1].someNumber = &structArray[0].arr[3];

    sPointer = &s;

    // Создание указателя pointer и присвоение ему адреса четвёртого элемента массива arr структуры s через указатель sPointer
    int* pointer = &sPointer->arr[3];

    s.arr[3] = 72;

    // Вывод значения, на которое указывает указатель pointer (72)
    std::cout << *pointer;

    // Создание экземпляра структуры StructWithArray с именем memory и заполнение его памяти нулями
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}