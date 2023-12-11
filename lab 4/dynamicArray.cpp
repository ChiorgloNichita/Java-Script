// dynamicArray.cpp

#include "dynamicArray.h"

// Функция для добавления элемента в массив
void addElementToArray(DynamicArray *array, int element)
{
    // Если массив полный, увеличиваем его емкость в два раза
    if (array->length == array->capacity) {
        array->capacity *= 2;
        int *newData = new int[array->capacity];
        // Копируем старые данные в новый массив
        std::copy(array->data, array->data + array->length, newData);
        delete[] array->data;
        array->data = newData;
    }

    // Добавляем элемент в конец массива
    array->data[array->length++] = element;
}

// Функция для получения текущего куска массива в виде std::vector
std::vector<int> getCurrentVector(const DynamicArray *array)
{
    // Создаем вектор из текущего куска массива
    return std::vector<int>(array->data, array->data + array->length);
}
