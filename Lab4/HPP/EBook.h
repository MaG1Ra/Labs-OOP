#ifndef LAB4_EBOOK_H
#define LAB4_EBOOK_H
#include "DigitalPublication.h"
class EBook : public DigitalPublication {
public:
    EBook(const std::string& title_, const std::string& isbn_, int fileSize_, const std::string& format_);
    EBook(const EBook& other);
    EBook& operator=(const EBook& other);
    ~EBook() override;
    std::string getType() const override {
        return "EBook";
    }
    void printInfo() const override;
};
#endif //LAB4_EBOOK_H