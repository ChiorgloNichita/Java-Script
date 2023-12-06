// dynamicArray.h

#pragma once
#include <iostream>

struct DynamicArray {
    int* values = nullptr;
    int length = 0;
    int capacity = 0;

    DynamicArray(int);

    void coutValues();

    ~DynamicArray(); // Добавляем деструктор для освобождения памяти
};
