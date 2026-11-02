/**
 * @file RGBColor.cpp
 * @brief Реализация класса RGBColor.
 * @details Описание интерфейса класса и его операций находится в RGBColor.h.
 *          Здесь приведены замечания по реализации.
 */
#include "RGBColor.h"
#include <iostream>

/**
 * @details Определение статического поля. Изначально в палитре нет ни одного цвета.
 */
int RGBColor::counter = 0;

/**
 * @details Поля инициализируются значениями по умолчанию (0, 0, 0), счётчик палитры увеличивается на 1.
 */
RGBColor::RGBColor() {
    counter++;
}

/**
 * @details Каналы задаются списком инициализации, счётчик палитры увеличивается на 1.
 */
RGBColor::RGBColor(unsigned char red_, unsigned char green_, unsigned char blue_) :
red(red_), green(green_), blue(blue_) {
    counter++;
}

/**
 * @details Копируются только каналы цвета, счётчик палитры увеличивается на 1.
 */
RGBColor::RGBColor(const RGBColor& other) {
    red = other.red;
    green = other.green;
    blue = other.blue;
    counter++;
}

/**
 * @details Нетривиальный деструктор: при уничтожении объекта счётчик палитры уменьшается на 1.
 */
RGBColor::~RGBColor() {
    counter--;
}

/**
 * @details Значение сначала сравнивается с границами 0 и 255 в типе `int`,
 *          и только потом приводится к `unsigned char`. Поэтому переполнения не происходит.
 */
unsigned char RGBColor::clamp(int value) {
    if (value < 0) {
        return 0;
    }
    if (value > 255) {
        return 255;
    }
    return static_cast<unsigned char>(value);
}

/**
 * @details Веса каналов соответствуют восприятию яркости человеком:
 *          зелёный вносит наибольший вклад, синий наименьший.
 *          Константы заданы как `float`, результат приводится к `double`.
 */
double RGBColor::luminance() const {
    return 0.2126f * red + 0.7152f * green + 0.0722f * blue;
}

unsigned char RGBColor::getRGBColorRed() const {
    return red;
}

unsigned char RGBColor::getRGBColorGreen() const {
    return green;
}

unsigned char RGBColor::getRGBColorBlue() const {
    return blue;
}

int RGBColor::getCounter() {
    return counter;
}

int RGBColor::getReqCounter() const {
    return req_counter;
}

void RGBColor::print() const {
    std::cout << "RGB (" << static_cast<int>(red) << ", " << static_cast<int>(green) << ", " << static_cast<int>(blue) << ")\n";
}

/**
 * @details Канал вычисляется как `clamp(канал + 1)`. Изменяется сам объект, он же и возвращается.
 */
RGBColor& RGBColor::operator++() {
    red = clamp(red +1);
    green = clamp(green +1);
    blue = clamp(blue +1);
    req_counter++;
    return *this;
}

/**
 * @details Копия исходного цвета сохраняется в `old`, затем меняется сам объект.
 *          Возвращается копия по значению, поэтому постфиксная форма медленнее префиксной.
 */
RGBColor RGBColor::operator++(int) {
    RGBColor old = *this;
    red = clamp(red +1);
    green = clamp(green +1);
    blue = clamp(blue +1);
    req_counter++;
    return old;
}

/**
 * @details Канал вычисляется как `clamp(канал - 1)`. Изменяется сам объект, он же и возвращается.
 */
RGBColor& RGBColor::operator--() {
    red = clamp(red - 1);
    green = clamp(green - 1);
    blue = clamp(blue - 1);
    req_counter++;
    return *this;
}

/**
 * @details Копия исходного цвета сохраняется в `old`, затем меняется сам объект.
 */
RGBColor RGBColor::operator--(int) {
    RGBColor old = *this;
    red = clamp(red - 1);
    green = clamp(green - 1);
    blue = clamp(blue - 1);
    req_counter++;
    return old;
}

/**
 * @details Сложение выполняется в типе `int`, затем результат ограничивается функцией clamp().
 */
RGBColor& RGBColor::operator+=(const RGBColor& rhs) {
    red = clamp(static_cast<int>(red) + rhs.red);
    green = clamp(static_cast<int>(green) + rhs.green);
    blue = clamp(static_cast<int>(blue) + rhs.blue);
    req_counter++;
    return *this;
}

/**
 * @details Вычитание выполняется в типе `int`, поэтому отрицательный результат не превращается
 *          в большое положительное число, а ограничивается нулём функцией clamp().
 */
RGBColor& RGBColor::operator-=(const RGBColor& rhs) {
    red = clamp(static_cast<int>(red) - rhs.red);
    green = clamp(static_cast<int>(green) - rhs.green);
    blue = clamp(static_cast<int>(blue) - rhs.blue);
    req_counter++;
    return *this;
}

/**
 * @details Деление нацело, дробная часть отбрасывается. Наибольшее произведение
 *          `255 * 255 = 65025` помещается в `int`.
 */
RGBColor& RGBColor::operator*=(const RGBColor& rhs) {
    red = clamp(static_cast<int>(red) * rhs.red / 255);
    green = clamp(static_cast<int>(green) * rhs.green / 255);
    blue = clamp(static_cast<int>(blue) * rhs.blue / 255);
    req_counter++;
    return *this;
}

/**
 * @details Сначала выполняется умножение на 255, и только потом деление, чтобы не потерять
 *          точность при целочисленном делении. Если канал делителя равен 0,
 *          результат равен 255 (защита от деления на ноль).
 */
RGBColor& RGBColor::operator/=(const RGBColor& rhs) {
    red = rhs.red ? clamp(red * 255 / rhs.red) : 255;
    green = rhs.green ? clamp(green * 255 / rhs.green) : 255;
    blue = rhs.blue ? clamp(blue * 255 / rhs.blue) : 255;
    req_counter++;
    return *this;
}

/**
 * @details Левый операнд принят по значению (копия). Изменяется копия, а не исходный объект.
 */
RGBColor operator+(RGBColor lhs, const RGBColor& rhs) {
    lhs += rhs;
    return lhs;
}

/**
 * @details Левый операнд принят по значению (копия). Изменяется копия, а не исходный объект.
 */
RGBColor operator-(RGBColor lhs, const RGBColor& rhs) {
    lhs -= rhs;
    return lhs;
}

/**
 * @details Левый операнд принят по значению (копия). Изменяется копия, а не исходный объект.
 */
RGBColor operator*(RGBColor lhs, const RGBColor& rhs) {
    lhs *= rhs;
    return lhs;
}

/**
 * @details Левый операнд принят по значению (копия). Изменяется копия, а не исходный объект.
 */
RGBColor operator/(RGBColor lhs, const RGBColor& rhs) {
    lhs /= rhs;
    return lhs;
}

/**
 * @details Счётчик `req_counter` изменяется в константном методе, потому что объявлен как `mutable`.
 */
bool RGBColor::operator<(const RGBColor& rhs) const {
    req_counter++;
    return luminance() < rhs.luminance();
}

/**
 * @details Счётчик `req_counter` увеличивается у левого операнда, в том числе если он `const`.
 */
bool RGBColor::operator>(const RGBColor& rhs) const {
    req_counter++;
    return luminance() > rhs.luminance();
}

/**
 * @details Сравниваются значения luminance() обоих цветов.
 */
bool RGBColor::operator<=(const RGBColor& rhs) const {
    req_counter++;
    return luminance() <= rhs.luminance();
}

/**
 * @details Сравниваются значения luminance() обоих цветов.
 */
bool RGBColor::operator>=(const RGBColor& rhs) const {
    req_counter++;
    return luminance() >= rhs.luminance();
}

/**
 * @details Значения luminance() сравниваются напрямую, без допуска. Для одинаковых каналов
 *          вычисления идентичны, поэтому результат точный.
 */
bool RGBColor::operator==(const RGBColor& rhs) const {
    req_counter++;
    return luminance() == rhs.luminance();
}

/**
 * @details Результат противоположен RGBColor::operator==.
 */
bool RGBColor::operator!=(const RGBColor& rhs) const {
    req_counter++;
    return luminance() != rhs.luminance();
}