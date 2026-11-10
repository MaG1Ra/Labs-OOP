#ifndef LAB4_HYBRIDBOOK_H
#define LAB4_HYBRIDBOOK_H
#include "DigitalPublication.h"
#include "Book.h"
class HybridBook : public Book, public DigitalPublication {
public:
    HybridBook(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_,const std::string& author_, int fileSize_, const std::string& format_);
    HybridBook(const HybridBook& other);
    HybridBook& operator=(const HybridBook& other);
    ~HybridBook() override;
    std::string getTitle() const override;
    std::string getISBN() const override;
    std::string getInfo() const override{
        return Book::getInfo() + "; electronic version: " + DigitalPublication::getInfo();
    }
    std::string getType() const override {
        return "HybridBook";
    }
    void printInfo() const override;
};
#endif //LAB4_HYBRIDBOOK_H