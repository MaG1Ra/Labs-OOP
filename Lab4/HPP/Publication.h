#ifndef LAB4_PUBLICATION_H
#define LAB4_PUBLICATION_H
#include <string>
#include <vector>
class Publication {
protected:
    std::string title;
    std::string isbn;
    static int totalCount;
public:
    virtual std::string getTitle() const = 0;
    virtual std::string getISBN() const = 0;
    virtual void printInfo() const = 0;
    virtual std::string getType() const {
        return "Publication";
    }
    Publication(const Publication& other);
    Publication(const std::string& title, const std::string& isbn);
    Publication& operator=(const Publication& other);
    virtual ~Publication();
    static Publication* findByISBN(std::string);
    static int getTotalCount();
    static std::vector<Publication*> registry;
    friend std::ostream& operator<<(std::ostream&, const Publication&);
};
#endif //LAB4_PUBLICATION_H