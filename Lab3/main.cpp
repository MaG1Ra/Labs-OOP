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
    std::cout << "Цветов в палитре: " << RGBColor::getCounter() << "\n\n";

    std::cout << "2. Статическое поле и деструктор\n";
    std::cout << "Цветов в палитре сейчас: " << RGBColor::getCounter() << "\n";
    {
        RGBColor tmp1(1, 2, 3);
        RGBColor tmp2(4, 5, 6);
        std::cout << "После создания 2 объектов в блоке: " << RGBColor::getCounter() << "\n";
    }
    std::cout << "После выхода из блока работает деструктор: " << RGBColor::getCounter() << "\n";

    return 0;
}