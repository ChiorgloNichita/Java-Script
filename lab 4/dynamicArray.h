// dynamicArray.h

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cassert>
#include <algorithm>
#include <vector>

struct DynamicArray
{
    int* data;       // Указатель на массив данных
    size_t capacity;  // Емкость массива
    size_t length;    // Текущая длина массива

    // Конструктор с параметром (начальная емкость)
    DynamicArray(size_t capacity = 4);

    // Деструктор для освобождения памяти
    ~DynamicArray();

    // Получение текущей емкости массива    
    inline size_t getCapacity() const { return capacity; }

    // Получение текущей длины массива
    inline size_t getLength() const { return length; }

    // Добавление элемента в массив
    void addElement(int element);

    // Получение элемента по индексу с проверкой длины
    int getElementAtIndex(size_t index) const;

    // Получение текущего массива в виде std::vector
    std::vector<int> getCurrentVector() const;
};

// Функция для добавления элемента в массив
void addElementToArray(DynamicArray* array, int element);

// Функция для получения текущего массива в виде std::vector
std::vector<int> getCurrentVector(const DynamicArray* array);

#endif // DYNAMIC_ARRAY_H
