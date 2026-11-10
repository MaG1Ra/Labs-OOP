#ifndef LAB4_MAGAZINE_H
#define LAB4_MAGAZINE_H
#include "PrintedPublication.h"
class Magazine : public PrintedPublication {
int issueNumber;
public:
    Magazine(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_, int issueNumber);
    Magazine(const Magazine& other);
    Magazine& operator=(const Magazine& other);
    ~Magazine() override;
    int getIssueNumber() const;
    std::string getInfo() const override {
        return "Magazine issue №" + std::to_string(issueNumber) + ", " + PrintedPublication::getInfo();
    }
    std::string getType() const override {
        return "Magazine";
    }
    void printInfo() const override;
};
#endif //LAB4_MAGAZINE_H