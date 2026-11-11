/**
 * \file DigitalPublication.cpp
 * \brief Реализация класса DigitalPublication.
 */
#include "../HPP/DigitalPublication.h"

/// Начальное значение счётчика электронных изданий.
int DigitalPublication::digitalCount = 0;

/**
 * \brief Конструктор с параметрами.
 * \param title_    Название.
 * \param isbn_     ISBN.
 * \param fileSize_ Размер файла в КБ.
 * \param format_   Формат файла.
 * \details Инициализирует виртуальную базу Publication, увеличивает digitalCount.
 */
DigitalPublication::DigitalPublication(const std::string &title_, const std::string &isbn_, int fileSize_, const std::string &format_)
: Publication(title_, isbn_), fileSize(fileSize_), format(format_) {
    digitalCount++;
}

/**
 * \brief Конструктор копирования.
 * \param other Копируемый объект.
 * \details Копия — новое электронное издание, поэтому digitalCount увеличивается.
 */
DigitalPublication::DigitalPublication(const DigitalPublication &other) : Publication(other), fileSize(other.fileSize), format(other.format) {
    digitalCount++;
}

/**
 * \brief Оператор присваивания.
 * \param other Присваиваемый объект.
 * \return Ссылка на *this.
 * \details Копирует базу, fileSize и format. Счётчик digitalCount не меняется.
 */
DigitalPublication& DigitalPublication::operator=(const DigitalPublication &other) {
    if (this != &other) {
        Publication::operator=(other);
        fileSize = other.fileSize;
        format = other.format;
    }
    return *this;
}

/// \brief Деструктор. Уменьшает digitalCount.
DigitalPublication::~DigitalPublication() {
    digitalCount--;
}

/// \brief Возвращает название издания.
/// \return Название.
std::string DigitalPublication::getTitle() const {
    return title;
}

/// \brief Возвращает ISBN издания.
/// \return ISBN.
std::string DigitalPublication::getISBN() const {
    return isbn;
}

/// \brief Возвращает размер файла.
/// \return Размер в КБ.
int DigitalPublication::getFileSize() const {
    return fileSize;
}

/// \brief Возвращает формат файла.
/// \return Строка с форматом.
std::string DigitalPublication::getFormat() const {
    return format;
}

/// \brief Возвращает число существующих электронных изданий.
/// \return Значение digitalCount.
int DigitalPublication::getDigitalCount() {
    return digitalCount;
}
