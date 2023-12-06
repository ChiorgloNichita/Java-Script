#include <span>

struct DynamicArray {
    int* values = nullptr;
    int length = 0, capacity = 0;

    DynamicArray(int);
    ~DynamicArray();

    void printValues() const;
};

DynamicArray createDynamicArray(int capacity = 5);
DynamicArray createDefaultDynamicArray();
void addElementToArray(DynamicArray& arr, int value);
int getElementByIndex(const DynamicArray& arr, int index);
std::span<int> getCurrentSpan(const DynamicArray& arr);
void destroyMemory(DynamicArray& arr);


