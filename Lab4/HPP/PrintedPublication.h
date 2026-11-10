#ifndef LAB4_PRINTEDPUBLICATION_H
#define LAB4_PRINTEDPUBLICATION_H
#include "../HPP/Publication.h"

class PrintedPublication : virtual public Publication {
protected:
    int pages;
    std::string publisher;
public:
    PrintedPublication(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher);
    PrintedPublication(const PrintedPublication& other);
    PrintedPublication& operator=(const PrintedPublication& other);
    ~PrintedPublication() override;
    virtual std::string getInfo() const {
        return "Printed: " + getTitle() + ", " + std::to_string(pages) + " pages";
    }
    std::string getType() const override {
        return "PrintedPublication";
    }
    std::string getTitle() const override;
    std::string getISBN() const override;
    int getPages() const;
    std::string getPublisher() const;
};
#endif //LAB4_PRINTEDPUBLICATION_H