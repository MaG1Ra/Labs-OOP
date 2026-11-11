/**
 * \file EBook.cpp
 * \brief Реализация класса EBook.
 */
#include "../HPP/EBook.h"

/**
 * \brief Конструктор с параметрами.
 * \param title_    Название.
 * \param isbn_     ISBN.
 * \param fileSize_ Размер файла в КБ.
 * \param format_   Формат файла.
 */
EBook::EBook(const std::string &title_, const std::string &isbn_, int fileSize_, const std::string &format_)
    : Publication(title_, isbn_), DigitalPublication(title_, isbn_, fileSize_, format_) {}

/**
 * \brief Конструктор копирования.
 * \param other Копируемая электронная книга.
 */
EBook::EBook(const EBook &other) : Publication(other), DigitalPublication(other) {}

/**
 * \brief Оператор присваивания.
 * \param other Присваиваемая электронная книга.
 * \return Ссылка на *this.
 */
EBook &EBook::operator=(const EBook &other) {
    if (this != &other) {
        DigitalPublication::operator=(other);
    }
    return *this;
}

/// \brief Деструктор.
EBook::~EBook() {}

/// \brief Печатает в cout строку <tt>[EBook] ... | описание</tt>.
void EBook::printInfo() const {
    std::cout << *this << " | " << getInfo() << '\n';
}