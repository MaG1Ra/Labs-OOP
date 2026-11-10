#ifndef LAB4_DIGITALPUBLICATION_H
#define LAB4_DIGITALPUBLICATION_H
#include "Publication.h"

class DigitalPublication : virtual public Publication {
    int fileSize;
    std::string format;
    static int digitalCount;
public:
    DigitalPublication(const std::string&title_, const std::string&isbn_, int filesize_, const std::string& format_);
    DigitalPublication(const DigitalPublication& other);
    DigitalPublication& operator=(const DigitalPublication& other);
    ~DigitalPublication() override;
    std::string getTitle() const override;
    std::string getISBN() const override;
    int getFileSize() const;
    std::string getFormat() const;
    virtual std::string getInfo() const {
        return "Size: " + std::to_string(fileSize) + " KB, format: " + format;
    }
    std::string getType() const override {
        return "DigitalPublication";
    }
    static int getDigitalCount();
};
#endif //LAB4_DIGITALPUBLICATION_H