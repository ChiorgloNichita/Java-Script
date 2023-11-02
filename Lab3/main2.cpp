#include <iostream>

static int hello(int x) {
    return x + 1 ;
}

int main() {
    int result = hello(5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
