#include <iostream>
#include <cassert>
#include <span> // Добавлен заголовок для std::span
#include <algorithm> // Добавлен заголовок для std::max

struct DynamicArray {
    int* values;
    size_t length;
    size_t capacity;

    // Конструктор
    DynamicArray(size_t initialCapacity = 5)
        : values(new int[initialCapacity]), length(0), capacity(std::max<size_t>(initialCapacity, 1)) {}

    // Деструктор
    ~DynamicArray() {
        delete[] values;
    }
};

// Функция для создания динамического массива с указанной емкостью
DynamicArray createDynamicArrayWithCapacity(size_t capacity = 5) {
    return DynamicArray(std::max<size_t>(capacity, 1));
}

// Функция для добавления элемента в массив
void addElementToArray(DynamicArray& arr, int value) {
    if (arr.length + 1 >= arr.capacity) {
        
        arr.capacity *= 2;
        int* newValues = new int[arr.capacity];
        for (size_t i = 0; i < arr.length; i++) {
            newValues[i] = arr.values[i];
        }
        delete[] arr.values;
        arr.values = newValues;
    }
    arr.values[arr.length] = value;
    arr.length += 1;
}

// Функция для получения элемента по индексу
int getElementAtIndex(const DynamicArray& arr, size_t index) {
    if (index < arr.length) {
        return arr.values[index];
    } else {
        return -100000; // Возвращаем значение, указывающее на ошибку 
    }
}

// Функция для уничтожения динамического массива
void destroyDynamicArray(DynamicArray& arr) {
    arr.capacity = 1;
    arr.length = 0;
    delete[] arr.values;
}
std::span<int> getCurrentSpan(const DynamicArray& arr) {
    return std::span<int>(arr.values, arr.length);
}
int main() {
    // Test 1
    DynamicArray arr1 = createDynamicArrayWithCapacity(10);
    assert(arr1.capacity == 10);
    std::cout << "Test 1: Create dynamic array with custom capacity - Passed" << std::endl;

    // Test 2
    DynamicArray arr2 = createDynamicArray();
    assert(arr2.capacity == 5);
    std::cout << "Test 2: Create dynamic array with default capacity - Passed" << std::endl;

    // Test 3
    addElementToArray(arr2, 5);
    assert(arr2.capacity == 5);
    addElementToArray(arr2, 10);
    assert(arr2.capacity == 10);
    addElementToArray(arr2, 20);
    assert(arr2.capacity == 20);
    std::cout << "Test 3" << std::endl;

    // Test 4
    int element = getElementAtIndex(arr2, 2);
    assert(element == 20);
    std::cout << "Test 4" << std::endl;

    // Test 5
    addElementToArray(arr2, 30);
    std::span<int> span = getCurrentSpan(&arr2);
    assert(span.size() == 4);
    assert(span[0] == 5 && span[1] == 10 && span[2] == 20 && span[3] == 30);
    std::cout << "Test 5" << std::endl;

    // Test 6
    destroyDynamicArray(&arr1);
    destroyDynamicArray(&arr2);
    assert(arr1.values == nullptr && arr2.values == nullptr);
    std::cout << "Test 6" << std::endl;

    std::cout << "All tests" << std::endl;

    return 0;
}
