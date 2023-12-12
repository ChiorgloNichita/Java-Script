// dynamicArray.cpp

#include "dynamicArray.h"

// Функция для добавления элемента в массив
void addElementToArray(DynamicArray *array, int element)
{
    // Если массив полный, увеличиваем его емкость
    if (array->length == array->capacity) {
        array->capacity = std::max(array->capacity * 2, static_cast<size_t>(1));
        array->data.resize(array->capacity);
    }

    // Добавляем элемент в конец массива
    array->data[array->length++] = element;
}

// Функция для получения текущего массива в виде std::vector
std::vector<int> getCurrentVector(const DynamicArray *array)
{
    // Создаем вектор из текущего массива
    return array->data;
}
