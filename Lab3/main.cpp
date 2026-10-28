/**
 * @file main.cpp
 * @brief Демонстрация работы класса RGBColor.
 * @details Файл содержит функцию main(), в которой по порядку показаны конструкторы,
 *          статическое поле, деструктор, все перегруженные операторы,
 *          а также `explicit` и `mutable`.
 */
/**
 * @mainpage Лабораторная работа: перегрузка функций и методов
 *
 * @section intro Описание
 * Программа для работы с палитрой цветов. Цвет представлен тремя каналами
 * (красный, зелёный, синий) в диапазоне 0–255 и описывается классом RGBColor.
 * Количество цветов в созданной палитре можно узнать вызовом RGBColor::getCounter().
 *
 * @section files Файлы проекта
 * - RGBColor.h: объявление класса с описанием интерфейса;
 * - RGBColor.cpp: реализация класса;
 * - main.cpp: демонстрация всех возможностей в функции main().
 *
 * @section tasks Соответствие пунктам задания
 * | № | Пункт задания | Где реализовано |
 * |---|---------------|-----------------|
 * | 1 | Три конструктора | по умолчанию, с параметрами, копирования |
 * | 2 | Унарные операции: постфикс и префикс, инкремент и декремент | `operator++`, `operator--` (по две формы) |
 * | 3 | Арифметическое присваивание | `operator+=`, `operator-=`, `operator*=`, `operator/=` |
 * | 4 | Бинарные операции | `+`, `-`, `*`, `/` через составные операторы; `<`, `>`, `<=`, `>=`, `==`, `!=` по яркости |
 * | 5 | `explicit` и `mutable` | конструктор с параметрами; поле RGBColor::req_counter |
 * | 6 | Статическое поле | RGBColor::counter |
 * | 7 | Нетривиальный деструктор | `~RGBColor()` уменьшает RGBColor::counter |
 * | 8 | Демонстрация в main() | функция main() |
 * | 9 | `explicit` предотвращает неявное преобразование | раздел 7 функции main() |
 * | 10 | `const`-объект и `mutable`-поле | раздел 8 функции main() |
 */
#include "RGBColor.h"
#include <iostream>

/**
 * @brief Точка входа: последовательно показывает работу класса RGBColor.
 * @details Вывод разбит на восемь разделов:
 * -# Конструкторы: по умолчанию, с параметрами, копирования; количество цветов в палитре.
 * -# Статическое поле и деструктор: счётчик палитры внутри вложенного блока.
 * -# Унарные операции: префиксные и постфиксные `++` и `--`, насыщение на границах 0 и 255.
 * -# Арифметическое присваивание: `+=`, `-=`, `*=`, `/=`, в том числе деление на чёрный цвет.
 * -# Бинарные операции `+`, `-`, `*`, `/`: исходные объекты не меняются.
 * -# Сравнение цветов по яркости.
 * -# `explicit`: неявная форма создания показана закомментированной строкой, которая не компилируется.
 * -# `mutable`: у `const`-объекта после сравнений увеличивается счётчик обращений.
 * @return 0 при нормальном завершении.
 */
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

    std::cout << "7. Демонстрация работы explicit\n";
    RGBColor good(10, 20, 30);
    good.print();
    // RGBColor bad = {10, 20, 30};
    // bad.print();
    std::cout << "(неявные формы RGBColor ... = {...} не компилируются)\n\n";

    std::cout << "8. Демонстрация работы mutable\n";
    const RGBColor constColor(120, 130, 140);
    std::cout << "req_counter до: " << constColor.getReqCounter() << "\n";
    bool r1 = constColor > dark;
    bool r2 = constColor >= dark;
    bool r3 = constColor != light;
    std::cout << "результаты: " << r1 << " " << r2 << " " << r3 << "\n";
    std::cout << "req_counter после: " << constColor.getReqCounter() << " изменён у const-объекта\n\n";
    return 0;
}