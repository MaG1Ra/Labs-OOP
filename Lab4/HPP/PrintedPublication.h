#ifndef LAB4_PRINTEDPUBLICATION_H
#define LAB4_PRINTEDPUBLICATION_H
#include "../HPP/Publication.h"
class PrintedPublication : public Publication {
    int pages;
    std::string publisher;
};
#endif //LAB4_PRINTEDPUBLICATION_H