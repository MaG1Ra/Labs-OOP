/**
 * \file HybridBook.cpp
 * \brief Реализация класса HybridBook.
 */
#include "../HPP/HybridBook.h"

/**
 * \brief Конструктор с параметрами.
 * \param title_     Название.
 * \param isbn_      ISBN.
 * \param pages_     Количество страниц.
 * \param publisher_ Издательство.
 * \param author_    Автор.
 * \param fileSize_  Размер электронной версии в КБ.
 * \param format_    Формат электронной версии.
 * \details Виртуальную базу Publication инициализирует именно HybridBook
 *          , затем вызываются Book и DigitalPublication.
 */
HybridBook::HybridBook(const std::string &title_, const std::string &isbn_, int pages_, const std::string &publisher_, const std::string &author_, int fileSize_, const std::string &format_)
    : Publication(title_, isbn_), Book(title_, isbn_, pages_, publisher_, author_), DigitalPublication(title_, isbn_, fileSize_, format_) {}

/**
 * \brief Конструктор копирования.
 * \param other Копируемая гибридная книга.
 */
HybridBook::HybridBook(const HybridBook &other) : Publication(other), Book(other), DigitalPublication(other) {}

/**
 * \brief Оператор присваивания.
 * \param other Присваиваемая гибридная книга.
 * \return Ссылка на *this.
 * \details Последовательно присваивает части Book и DigitalPublication.
 */
HybridBook &HybridBook::operator=(const HybridBook &other) {
    if (this != &other) {
        Book::operator=(other);
        DigitalPublication::operator=(other);
    }
    return *this;
}

/// \brief Деструктор.
HybridBook::~HybridBook() {}

/// \brief Возвращает название.
/// \return Название.
std::string HybridBook::getTitle() const {
    return Book::getTitle();
}

/// \brief Возвращает ISBN.
/// \return ISBN.
std::string HybridBook::getISBN() const {
    return Book::getISBN();
}

/// \brief Печатает в cout строку <tt>[HybridBook] ... | печатная и электронная части</tt>.
void HybridBook::printInfo() const {
    std::cout << *this << " | " << getInfo() << '\n';
}
