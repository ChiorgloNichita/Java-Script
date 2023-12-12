    // main.cpp

    #include "dynamicArray.h"
    #include <iostream>

    // Тест 1: Создание массива с начальной емкостью
    static void test1()
    {
        DynamicArray arr(10);
        assert(arr.getCapacity() == 10);
    }

    // Тест 2: Создание массива с емкостью по умолчанию и добавление элемента
    static void test2()
    {
        DynamicArray arr;
        assert(arr.getLength() == 0);
        addElementToArray(&arr, 5);
        assert(arr.getLength() == 1);
    }

    // Тест 3: Создание массива с начальной емкостью и добавление элементов
    static void test3()
    {
        DynamicArray arr(1);
        addElementToArray(&arr, 5);
        assert(arr.getCapacity() == 1);
        addElementToArray(&arr, 10);
        assert(arr.getCapacity() == 2);
        addElementToArray(&arr, 20);
        assert(arr.getCapacity() == 4);
    }

    // Тест 4: Создание массива, добавление элемента и доступ к элементу по индексу
    static void test4()
    {
        DynamicArray arr;
        addElementToArray(&arr, 5);
        int el = arr.getElementAtIndex(0);
        assert(el == 5);
    }

    // Тест 5: Создание массива, добавление нескольких элементов и получение текущего  вектора
    static void test5()
    {
        DynamicArray arr{};
        addElementToArray(&arr, 5);
        addElementToArray(&arr, 6);
        addElementToArray(&arr, 7);

        std::vector<int> vec = getCurrentVector(&arr);

        assert(vec.size() == 3);
        assert(vec[0] == 5);
        assert(vec[1] == 6);
        assert(vec[2] == 7);
    }

    int main()
    {
        // Запуск тестов
        test1();
        test2();
        test3();
        test4();
        test5();

        std::cout << "All tests passed!" << std::endl;

        return 0;
    }

