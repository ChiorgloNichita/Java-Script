// dynamicArray.cpp

#include "dynamicArray.h"

DynamicArray::DynamicArray(int capacity) {
    this->values = new int[capacity];
    this->capacity = capacity;
}

void DynamicArray::coutValues() {
    for (int i = 0; i < this->length; i++) {
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl << this->capacity << std::endl;
}

DynamicArray::~DynamicArray() {
    delete[] values; // Освобождаем память в деструкторе
}