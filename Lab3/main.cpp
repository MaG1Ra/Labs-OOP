#include "RGBColor.h"
#include <iostream>

int main() {
    std::cout << "1. Конструкторы\n";
    RGBColor color0;
    RGBColor color1(100, 50, 200);
    RGBColor color2(color1);
    std::cout << "color0:     "; color0.print();
    std::cout << "color1: "; color1.print();
    std::cout << "color2: "; color2.print();
    std::cout << "\n";

    return 0;
}