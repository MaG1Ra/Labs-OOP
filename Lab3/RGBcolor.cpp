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