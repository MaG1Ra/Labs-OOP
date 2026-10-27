#include "RGBColor.h"
#include <iostream>

int main() {
    std::cout << "1. Конструкторы\n";
    RGBColor color0;
    RGBColor color1(100, 50, 200);
    RGBColor color2(color1);
    std::cout << "color0: ";
    color0.print();
    std::cout << "color1: ";
    color1.print();
    std::cout << "color2: ";
    color2.print();
    std::cout << "Цветов в палитре: " << RGBColor::getCounter() << "\n\n";

    std::cout << "2. Статическое поле и деструктор\n";
    std::cout << "Цветов в палитре сейчас: " << RGBColor::getCounter() << "\n";
    {
        RGBColor tmp1(1, 2, 3);
        RGBColor tmp2(4, 5, 6);
        std::cout << "После создания 2 объектов в блоке: " << RGBColor::getCounter() << "\n";
    }
    std::cout << "После выхода из блока работает деструктор: " << RGBColor::getCounter() << "\n\n";

    std::cout << "3. Унарные операции\n";
    RGBColor color3(10, 20, 30);
    std::cout << "Начало: ";
    color3.print();
    ++color3;
    std::cout << "++color3: ";
    color3.print();
    RGBColor old = color3++;
    std::cout << "color3++ -> новый: ";
    color3.print();
    std::cout << "color3++ -> старый: ";
    old.print();
    --color3;
    std::cout << "--color3: ";
    color3.print();
    old = color3--;
    std::cout << "color3-- -> новый: ";
    color3.print();
    std::cout << "color3-- -> старый: ";
    old.print();
    RGBColor hi(255, 255, 255);
    RGBColor lo(0, 0, 0);
    ++hi;
    std::cout << "++ на 255: ";
    hi.print();
    --lo;
    std::cout << "-- на 0: ";
    lo.print();
    std::cout << "\n";

    std::cout << "4. Арифметическое присваивание\n";
    RGBColor a (100, 100, 100);
    const RGBColor b(50, 200, 255);
    std::cout << "a = ";
    a.print();
    std::cout << "b = ";
    b.print();
    RGBColor tmp= a;
    tmp += b;
    std::cout << "a += b: ";
    tmp.print();
    tmp = a;
    tmp -= b;
    std::cout << "a -= b: ";
    tmp.print();
    tmp = a;
    tmp *= b;
    std::cout << "a *= b: ";
    tmp.print();
    tmp = a;
    tmp /= b;
    std::cout << "a /= b: ";
    tmp.print();
    tmp = a;
    tmp /= RGBColor(0, 0, 0);
    std::cout << "a /= (0,0,0): ";
    tmp.print();
    std::cout << "\n";

    std::cout << "5. Бинарные операции\n";
    std::cout << "a + b: ";
    (a + b).print();
    std::cout << "a - b: ";
    (a - b).print();
    std::cout << "a * b: ";
    (a * b).print();
    std::cout << "a / b: ";
    (a / b).print();
    std::cout << "a после операций не изменился: ";
    a.print();
    RGBColor dark(10, 10, 10);
    RGBColor light(250, 250, 250);
    std::cout << "250 + 250 = 255: ";
    (light + light).print();
    std::cout << "10 - 250 = 0: ";
    (dark - light).print();
    std::cout << "\n";

    std::cout << "6. Сравнение по яркости\n";
    RGBColor same(color1);
    std::cout << std::boolalpha;
    std::cout << "dark < light: " << (dark < light) << "\n";
    std::cout << "dark > light: " << (dark > light) << "\n";
    std::cout << "dark <= light:" << (dark <= light) << "\n";
    std::cout << "dark >= light: " << (dark >= light) << "\n";
    std::cout << "color1 == same: " << (color1 == same) << "\n";
    std::cout << "color1 != same: " << (color1 != same) << "\n";
    std::cout << "dark == light: " << (dark == light) << "\n";
    std::cout << "dark != light: " << (dark != light) << "\n\n";
    return 0;
}