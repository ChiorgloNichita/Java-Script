#include <iostream>
#include <cassert>
#include <span>
#include <algorithm>

#include "dynamicArray.h"

int main() {
  // Тест 1: Создание динамического массива с пользовательской емкостью
  DynamicArray arr1(10);
  assert(arr1.capacity == 10);
  std::cout << "Тест 1: Пройден" << std::endl;

  // Тест 2: Создание динамического массива с емкостью по умолчанию
  DynamicArray arr2;
  assert(arr2.capacity == 5);
  std::cout << "Тест 2: Пройден" << std::endl;

  // Тест 3: Добавление элементов и расширение емкости
  addElementToArray(arr2, 5);
  assert(arr2.capacity == 5);
  addElementToArray(arr2, 10);
  assert(arr2.capacity == 10);
  addElementToArray(arr2, 20);
  assert(arr2.capacity == 20);
  std::cout << "Тест 3: Пройден" << std::endl;

  // Тест 4: Получение элемента по индексу
  int элемент = getElementAtIndex(arr2, 2);
  assert(элемент == 20);
  std::cout << "Тест 4: Пройден" << std::endl;

  // Тест 5: Добавление еще одного элемента и доступ к span
  addElementToArray(arr2, 30);
  std::span<int> span = getCurrentSpan(&arr2);
  assert(span.size() == 4);
  assert(span[0] == 5 && span[1] == 10 && span[2] == 20 && span[3] == 30);
  std::cout << "Тест 5: Пройден" << std::endl;

  // Тест 6: Уничтожение динамических массивов
  destroyDynamicArray(&arr1);
  destroyDynamicArray(&arr2);
  assert(arr1.values == nullptr && arr2.values == nullptr);
  std::cout << "Тест 6: Пройден" << std::endl;

  std::cout << "Все тесты пройдены." << std::endl;

  return 0;
}
