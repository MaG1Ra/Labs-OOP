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

void RGBColor::print() const {
    std::cout << "RGB (" << static_cast<int>(red) << ", " << static_cast<int>(green) << ", " << static_cast<int>(blue) << ")\n";
}

RGBColor& RGBColor::operator++() {
    red = clamp(red +1);
    green = clamp(green +1);
    blue = clamp(blue +1);
    return *this;
}

RGBColor RGBColor::operator++(int) {
    RGBColor old = *this;
    red = clamp(red +1);
    green = clamp(green +1);
    blue = clamp(blue +1);
    return old;
}

RGBColor& RGBColor::operator--() {
    red = clamp(red - 1);
    green = clamp(green - 1);
    blue = clamp(blue - 1);
    return *this;
}

RGBColor RGBColor::operator--(int) {
    RGBColor old = *this;
    red = clamp(red - 1);
    green = clamp(green - 1);
    blue = clamp(blue - 1);
    return old;
}