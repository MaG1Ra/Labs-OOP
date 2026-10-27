#include "RGBColor.h"
#include <iostream>

int RGBColor::counter = 0;

RGBColor::RGBColor() {
    counter++;
}

RGBColor::RGBColor(unsigned char red_, unsigned char green_, unsigned char blue_) :
red(red_), green(green_), blue(blue_) {
    counter++;
}

RGBColor::RGBColor(const RGBColor& other) {
    red = other.red;
    green = other.green;
    blue = other.blue;
    counter++;
}

RGBColor::~RGBColor() {
    counter--;
}

unsigned char RGBColor::clamp(int value) {
    if (value < 0) {
        return 0;
    }
    if (value > 255) {
        return 255;
    }
    return static_cast<unsigned char>(value);
}

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

RGBColor& RGBColor::operator++() {
    red = clamp(red +1);
    green = clamp(green +1);
    blue = clamp(blue +1);
    req_counter++;
    return *this;
}

RGBColor RGBColor::operator++(int) {
    RGBColor old = *this;
    red = clamp(red +1);
    green = clamp(green +1);
    blue = clamp(blue +1);
    req_counter++;
    return old;
}

RGBColor& RGBColor::operator--() {
    red = clamp(red - 1);
    green = clamp(green - 1);
    blue = clamp(blue - 1);
    req_counter++;
    return *this;
}

RGBColor RGBColor::operator--(int) {
    RGBColor old = *this;
    red = clamp(red - 1);
    green = clamp(green - 1);
    blue = clamp(blue - 1);
    req_counter++;
    return old;
}

RGBColor& RGBColor::operator+=(const RGBColor& rhs) {
    red = clamp(static_cast<int>(red) + rhs.red);
    green = clamp(static_cast<int>(green) + rhs.green);
    blue = clamp(static_cast<int>(blue) + rhs.blue);
    req_counter++;
    return *this;
}

RGBColor& RGBColor::operator-=(const RGBColor& rhs) {
    red = clamp(static_cast<int>(red) - rhs.red);
    green = clamp(static_cast<int>(green) - rhs.green);
    blue = clamp(static_cast<int>(blue) - rhs.blue);
    req_counter++;
    return *this;
}

RGBColor& RGBColor::operator*=(const RGBColor& rhs) {
    red = clamp(static_cast<int>(red) * rhs.red / 255);
    green = clamp(static_cast<int>(green) * rhs.green / 255);
    blue = clamp(static_cast<int>(blue) * rhs.blue / 255);
    req_counter++;
    return *this;
}

RGBColor& RGBColor::operator/=(const RGBColor& rhs) {
    red = rhs.red ? clamp(red * 255 / rhs.red) : 255;
    green = rhs.green ? clamp(green * 255 / rhs.green) : 255;
    blue = rhs.blue ? clamp(blue * 255 / rhs.blue) : 255;
    req_counter++;
    return *this;
}

RGBColor operator+(RGBColor lhs, const RGBColor& rhs) {
    lhs += rhs;
    return lhs;
}

RGBColor operator-(RGBColor lhs, const RGBColor& rhs) {
    lhs -= rhs;
    return lhs;
}

RGBColor operator*(RGBColor lhs, const RGBColor& rhs) {
    lhs *= rhs;
    return lhs;
}

RGBColor operator/(RGBColor lhs, const RGBColor& rhs) {
    lhs /= rhs;
    return lhs;
}

bool RGBColor::operator<(const RGBColor& rhs) const {
    req_counter++;
    return luminance() < rhs.luminance();
}

bool RGBColor::operator>(const RGBColor& rhs) const {
    req_counter++;
    return luminance() > rhs.luminance();
}

bool RGBColor::operator<=(const RGBColor& rhs) const {
    req_counter++;
    return luminance() <= rhs.luminance();
}

bool RGBColor::operator>=(const RGBColor& rhs) const {
    req_counter++;
    return luminance() >= rhs.luminance();
}

bool RGBColor::operator==(const RGBColor& rhs) const {
    req_counter++;
    return luminance() == rhs.luminance();
}

bool RGBColor::operator!=(const RGBColor& rhs) const {
    req_counter++;
    return luminance() != rhs.luminance();
}