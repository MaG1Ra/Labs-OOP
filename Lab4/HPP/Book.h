#ifndef LAB4_BOOK_H
#define LAB4_BOOK_H
#include "PrintedPublication.h"
class Book : public PrintedPublication {
    std::string author;
public:
    Book(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_, const std::string& author_);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book() override;
    std::string getAuthor() const;
    std::string getInfo() const override {
        return "Author: " + author + ", " + PrintedPublication::getInfo();
    }
    std::string getType() const override {
        return "Book";
    }
    void printInfo() const override;
};
#endif //LAB4_BOOK_H