#ifndef LAB4_PUBLICATION_H
#define LAB4_PUBLICATION_H
#include <string>
class Publication {
public:
    virtual std::string getTitle() const = 0;
    virtual int getISNB() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Publication();
};
static int findByISBN(std::string);
#endif //LAB4_PUBLICATION_H