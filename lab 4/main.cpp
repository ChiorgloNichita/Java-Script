// main.cpp

#include <iostream>
#include <cassert>
#include "dynamicArray.h"

DynamicArray createDynamicArray(int capacity = 5) {
    DynamicArray* newArray = new DynamicArray(capacity);
    return *newArray;
}

void addElementToArray(DynamicArray& arr, int value) {
    if (arr.length + 1 >= arr.capacity) {
        arr.capacity *= 2;
        int* newValues = new int[arr.capacity];
        for (int i = 0; i < arr.length; i++) {
            newValues[i] = arr.values[i];
        }
        delete[] arr.values; // Освобождаем старую память
        arr.values = newValues;
    }
    arr.values[arr.length] = value;
    arr.length += 1;
}

int getElementByIndex(const DynamicArray& arr, int index) {
    if (arr.length - 1 >= index) {
        return arr.values[index];
    } else {
        return -100000;
    }
}

void destroyMemory(DynamicArray& arr) {
    arr.capacity = 1;
    arr.length = 0;
    delete[] arr.values;
    arr.values = nullptr; // Устанавливаем указатель в нуль после освобождения памяти
}

int main() {
    int cap;
    std::cout << "Give default value for capacity (0 if default)" << std::endl;
    std::cin >> cap;

    DynamicArray myArray = cap == 0 ? createDynamicArray() : createDynamicArray(cap);
    cap == 0 ? assert(myArray.capacity == 5) : assert(myArray.capacity == cap);
    addElementToArray(myArray, 10);
    myArray.coutValues();
    addElementToArray(myArray, 20);
    addElementToArray(myArray, 30);
    myArray.coutValues();

    int el = getElementByIndex(myArray, 2);
    assert(el == 30);

    destroyMemory(myArray);

    return 0;
}
