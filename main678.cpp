// main.cpp
#include <iostream>

static int hello(int x) {
    return x * 2;
}

int main() {
    int result = hello(42);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

