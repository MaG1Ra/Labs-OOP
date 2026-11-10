#include "../HPP/EBook.h"

EBook::EBook(const std::string &title_, const std::string &isbn_, int fileSize_, const std::string &format_)
    : Publication(title_, isbn_), DigitalPublication(title_, isbn_, fileSize_, format_) {}

EBook::EBook(const EBook &other) : Publication(other), DigitalPublication(other) {}

EBook &EBook::operator=(const EBook &other) {
    if (this != &other) {
        DigitalPublication::operator=(other);
    }
    return *this;
}

EBook::~EBook() {}

void EBook::printInfo() const {
    std::cout << *this << " | " << getInfo() << '\n';
}