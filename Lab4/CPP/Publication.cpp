#include "../HPP/Publication.h"
int Publication::totalCount = 0;

Publication::Publication(const Publication &other) {
    title = other.title;
    isbn = other.isbn;
    totalCount++;
    registry.push_back(this);
}

Publication::Publication(const std::string &title_, const std::string &isbn_) : title(title_), isbn(isbn_){
    totalCount++;
    registry.push_back(this);
}

Publication &Publication::operator=(const Publication &other) {
    if (this != &other) {
        title = other.title;
        isbn = other.isbn;
    }
    return *this;
}

Publication::~Publication() {
    for (auto it = registry.begin(); it != registry.end(); it++) {
        if (*it == this) {
            registry.erase(it);
            break;
        }
    }
    --totalCount;
}

int Publication::getTotalCount() {
    return totalCount;
}

Publication *Publication::findByISBN(std::string isbn) {
    for (Publication* p : registry) {
        if (p->getISBN() == isbn) {
            return p;
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Publication& p) {
    os << "[" << p.getType() << "] " << p.getTitle() << " (ISBN: " << p.getISBN() << ")";
    return os;
}