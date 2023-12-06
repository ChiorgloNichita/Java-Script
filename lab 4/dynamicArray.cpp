#include "dynamicArray.h"
#include <iostream>
#include <algorithm>

DynamicArray::DynamicArray(int capacity) : capacity(capacity), values(new int[capacity]) {}

DynamicArray::~DynamicArray() {
    delete[] values;
}

void DynamicArray::printValues() const {
    std::cout << "Array values: ";
    for (int i = 0; i < length; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << "\nCurrent capacity: " << capacity << std::endl;
}
