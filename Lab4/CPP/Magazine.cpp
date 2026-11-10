#include "../HPP/Magazine.h"

Magazine::Magazine(const std::string& title_, const std::string& isbn_, int pages_, const std::string&publisher_, int issueNumber_)
    : Publication(title_,isbn_), PrintedPublication(title_, isbn_, pages_, publisher_), issueNumber(issueNumber_) {}

Magazine::Magazine(const Magazine& other) : Publication(other), PrintedPublication(other), issueNumber(other.issueNumber) {}

Magazine &Magazine::operator=(const Magazine& other) {
    if (this != &other) {
        PrintedPublication::operator=(other);
        issueNumber = other.issueNumber;
    }
    return *this;
}
Magazine::~Magazine() {}

int Magazine::getIssueNumber() const {
    return issueNumber;
}

void Magazine::printInfo() const {
    std::cout << *this << " | " << getInfo() << '\n';
}