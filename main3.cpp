#include <stdlib.h>
#include <iostream>

int* stackMemory1()
{
    int a = 1; // Создается локальная переменная a и инициализируется значением 1
    return &a; // Возвращается указатель на локальную переменную a
}

int* stackMemory2()
{
    int b = 2; // Создается локальная переменная b и инициализируется значением 2
    return &b; // Возвращается указатель на локальную переменную b
}

int main()
{
    int* b = stackMemory1(); // Вызывается stackMemory1, b указывает на a
    int a1 = *b; // a1 получает значение, на которое указывает b (1)

    int* c = stackMemory2(); // Вызывается stackMemory2, c указывает на b
    int a2 = *c; // a2 получает значение, на которое указывает c (2)
    
    int a3 = *b; // a3 получает значение, на которое указывает b (2)

    std::cout << a1 << std::endl; //
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl; 
    std::cout << ((std::byte*) b - (std::byte*) c) << std::endl; 

    return 0;
}
