// dynamicArray.h

#pragma once
#include <iostream>

struct DynamicArray {
    int* values;
    int length;
    int capacity;

    // Функция для выделения памяти и инициализации массива
    void init(int initialCapacity) {
        length = 0;
        // Убеждаемся, что capacity как минимум 1
        capacity = (initialCapacity > 0) ? initialCapacity : 1;
        values = new int[capacity];
    }

    // Функция для вывода значений массива
    void coutValues() const {
        for (int i = 0; i < length; i++) {
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;
    }

    // Функция для освобождения памяти
    void freeMemory() {
        delete[] values;
        length = 0;
        capacity = 0;
        values = nullptr; 
    }
};

