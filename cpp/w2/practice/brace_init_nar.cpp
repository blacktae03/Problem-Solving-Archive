#include <iostream>

int main() {
    char c1(999); // WARNING
    char c2 = 999; // WARNING
    //char c3{999}; // ERROR
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    int i1(3.14); // WARNING
    int i2 = 3.14; // WARNING
    //int i3{3.14}; // ERROR
    std::cout << "i1: " << i1 << std::endl;
    std::cout << "i2: " << i2 << std::endl;
}
