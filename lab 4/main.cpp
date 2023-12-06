#include <cassert>
#include <iostream>
#include "dynamicArray.h"

int main() {
    int cap;
    std::cout << "Enter the initial capacity (0 for default): ";
    std::cin >> cap;

    DynamicArray myArray = cap == 0 ? createDefaultDynamicArray() : createDynamicArray(cap);
    assert(myArray.capacity == (cap == 0 ? 5 : cap));

    addElementToArray(myArray, 10);
    myArray.printValues();
    addElementToArray(myArray, 20);
    addElementToArray(myArray, 30);
    myArray.printValues();

    int el = getElementByIndex(myArray, 2);
    assert(el == 30);

    destroyMemory(myArray);

    return 0;
}
