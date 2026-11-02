#ifndef LAB4_DIGITALPUBLICATION_H
#define LAB4_DIGITALPUBLICATION_H
#include "../Publication.h"
class DigitalPublication : public Publication {
    int fileSize;
    std::string format;
};
#endif //LAB4_DIGITALPUBLICATION_H