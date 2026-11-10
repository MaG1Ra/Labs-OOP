#include "../HPP/PrintedPublication.h"

PrintedPublication::PrintedPublication(const std::string &title_, const std::string &isbn_,
    int pages_, const std::string &publisher) : Publication(title_, isbn_), pages(pages_), publisher(publisher){}

PrintedPublication::PrintedPublication(const PrintedPublication &other) : Publication(other), pages(other.pages), publisher(other.publisher){}

PrintedPublication& PrintedPublication::operator=(const PrintedPublication &other) {
    if (this !=&other) {
        Publication::operator=(other);
        pages = other.pages;
        publisher = other.publisher;
    }
    return *this;
}

PrintedPublication::~PrintedPublication() {}

std::string PrintedPublication::getTitle() const {
    return title;
}

std::string PrintedPublication::getISBN() const {
    return isbn;
}

int PrintedPublication::getPages() const {
    return pages;
}

std::string PrintedPublication::getPublisher() const {
    return publisher;
}