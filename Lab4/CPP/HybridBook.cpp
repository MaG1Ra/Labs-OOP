#include "../HPP/HybridBook.h"

HybridBook::HybridBook(const std::string &title_, const std::string &isbn_, int pages_, const std::string &publisher_, const std::string &author_, int fileSize_, const std::string &format_)
    : Publication(title_, isbn_), Book(title_, isbn_, pages_, publisher_, author_), DigitalPublication(title_, isbn_, fileSize_, format_) {}

HybridBook::HybridBook(const HybridBook &other) : Publication(other), Book(other), DigitalPublication(other) {}

HybridBook &HybridBook::operator=(const HybridBook &other) {
    if (this != &other) {
        Book::operator=(other);
        DigitalPublication::operator=(other);
    }
    return *this;
}

HybridBook::~HybridBook() {}

std::string HybridBook::getTitle() const {
    return Book::getTitle();
}

std::string HybridBook::getISBN() const {
    return Book::getISBN();
}

void HybridBook::printInfo() const {
    std::cout << *this << " | " << getInfo() << '\n';
}
