#include <iostream>

int hello(int x) {
    return x * 2;
}

int main() {
    int result = hello(5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
