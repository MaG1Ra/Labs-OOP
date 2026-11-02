#ifndef LAB4_PUBLICATION_H
#define LAB4_PUBLICATION_H
#include <string>
#include <vector>
class Publication {
protected:
    std::string title;
    std::string isbn;
public:
    virtual std::string getTitle() const = 0;
    virtual int getISNB() const = 0;
    virtual void printInfo() const = 0;
    Publication(const Publication& other);
    Publication& operator=(const Publication& other);
    virtual ~Publication();
    static int findByISBN(std::string);
    static int totalCount();
    std::vector<Publication*> registry;
    friend std::ostream& operator<<(std::ostream&, const Publication&);
};
#endif //LAB4_PUBLICATION_H