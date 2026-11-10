#include "../HPP/DigitalPublication.h"

int DigitalPublication::digitalCount = 0;

DigitalPublication::DigitalPublication(const std::string &title_, const std::string &isbn_, int fileSize_, const std::string &format_)
: Publication(title_, isbn_), fileSize(fileSize_), format(format_) {
    digitalCount++;
}

DigitalPublication::DigitalPublication(const DigitalPublication &other) : Publication(other), fileSize(other.fileSize), format(other.format) {
    digitalCount++;
}

DigitalPublication& DigitalPublication::operator=(const DigitalPublication &other) {
    if (this != &other) {
        Publication::operator=(other);
        fileSize = other.fileSize;
        format = other.format;
    }
    return *this;
}

DigitalPublication::~DigitalPublication() {
    digitalCount--;
}

std::string DigitalPublication::getTitle() const {
    return title;
}

std::string DigitalPublication::getISBN() const {
    return isbn;
}

int DigitalPublication::getFileSize() const {
    return fileSize;
}

std::string DigitalPublication::getFormat() const {
    return format;
}

int DigitalPublication::getDigitalCount() {
    return digitalCount;
}
