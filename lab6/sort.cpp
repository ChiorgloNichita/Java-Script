#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];  // Запоминаем текущий элемент
        int j = i - 1;      // Ищем место для вставки

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Сдвигаем больший элемент вправо
            --j;
        }

        arr[j + 1] = key;  // Вставляем элемент на найденное место
    }
}

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    std::cout << "Original Array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    insertionSort(numbers);

    std::cout << "Sorted Array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
