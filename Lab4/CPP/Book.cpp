#include "../HPP/Book.h"

Book::Book(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_, const std::string& author_)
    : Publication(title_, isbn_), PrintedPublication(title_, isbn_, pages_, publisher_), author(author_) {}

Book::Book(const Book& other) : Publication(other), PrintedPublication(other), author(other.author) {}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        PrintedPublication::operator=(other);
        author = other.author;
    }
    return *this;
}

Book::~Book() {}

std::string Book::getAuthor() const {
    return author;
}

void Book::printInfo() const {
    std::cout << *this << " | " << getInfo() << "\n";
}
