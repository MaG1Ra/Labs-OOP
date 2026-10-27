#ifndef OOP_RGBCOLOR_H
#define OOP_RGBCOLOR_H
class RGBColor {
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
    static int counter;
    unsigned char clamp(int value);
public:
    RGBColor();
    RGBColor(unsigned char red_, unsigned char green_, unsigned char blue_);
    RGBColor(const RGBColor& other);

    ~RGBColor();

    RGBColor& operator++();
    RGBColor operator++(int);
    RGBColor& operator--();
    RGBColor operator--(int);

    RGBColor& operator+=(const RGBColor& rhs);
    RGBColor& operator-=(const RGBColor& rhs);
    RGBColor& operator*=(const RGBColor& rhs);
    RGBColor& operator/=(const RGBColor& rhs);

    friend RGBColor operator+(RGBColor lhs, const RGBColor& rhs);
    friend RGBColor operator-(RGBColor lhs, const RGBColor& rhs);
    friend RGBColor operator*(RGBColor lhs, const RGBColor& rhs);
    friend RGBColor operator/(RGBColor lhs, const RGBColor& rhs);

    unsigned char getRGBColorRed() const;
    unsigned char getRGBColorGreen() const;
    unsigned char getRGBColorBlue() const;
    void print() const;
    static int getCounter();
};
#endif //OOP_RGBCOLOR_H