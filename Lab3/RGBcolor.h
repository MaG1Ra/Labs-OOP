#ifndef OOP_RGBCOLOR_H
#define OOP_RGBCOLOR_H
class RGBColor {
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
    static int counter;
    unsigned char clamp(int value);
    double luminance() const;
    mutable int req_counter = 0;
public:
    RGBColor();
    explicit RGBColor(unsigned char red_, unsigned char green_, unsigned char blue_);
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

    bool operator<(const RGBColor& rhs) const;
    bool operator>(const RGBColor& rhs) const;
    bool operator<=(const RGBColor& rhs) const;
    bool operator>=(const RGBColor& rhs) const;
    bool operator==(const RGBColor& rhs) const;
    bool operator!=(const RGBColor& rhs) const;

    unsigned char getRGBColorRed() const;
    unsigned char getRGBColorGreen() const;
    unsigned char getRGBColorBlue() const;
    void print() const;
    static int getCounter();
    int getReqCounter() const;
};
#endif //OOP_RGBCOLOR_H