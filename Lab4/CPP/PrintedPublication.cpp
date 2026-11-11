/**
 * \file PrintedPublication.cpp
 * \brief Реализация класса PrintedPublication.
 */
#include "../HPP/PrintedPublication.h"

/**
 * \brief Конструктор с параметрами.
 * \param title_    Название.
 * \param isbn_     ISBN.
 * \param pages_    Количество страниц.
 * \param publisher Издательство.
 * \details Инициализирует виртуальную базу Publication и собственные поля.
 */
PrintedPublication::PrintedPublication(const std::string &title_, const std::string &isbn_,
    int pages_, const std::string &publisher) : Publication(title_, isbn_), pages(pages_), publisher(publisher){}

/**
 * \brief Конструктор копирования.
 * \param other Копируемый объект.
 */
PrintedPublication::PrintedPublication(const PrintedPublication &other) : Publication(other), pages(other.pages), publisher(other.publisher){}

/**
 * \brief Оператор присваивания.
 * \param other Присваиваемый объект.
 * \return Ссылка на *this.
 * \details Проверяет самоприсваивание, затем копирует базу и поля pages, publisher.
 */
PrintedPublication& PrintedPublication::operator=(const PrintedPublication &other) {
    if (this !=&other) {
        Publication::operator=(other);
        pages = other.pages;
        publisher = other.publisher;
    }
    return *this;
}

/// \brief Деструктор.
PrintedPublication::~PrintedPublication() {}

/// \brief Возвращает название издания.
/// \return Название.
std::string PrintedPublication::getTitle() const {
    return title;
}

/// \brief Возвращает ISBN издания.
/// \return ISBN.
std::string PrintedPublication::getISBN() const {
    return isbn;
}

/// \brief Возвращает количество страниц.
/// \return Число страниц.
int PrintedPublication::getPages() const {
    return pages;
}

/// \brief Возвращает издательство.
/// \return Название издательства.
std::string PrintedPublication::getPublisher() const {
    return publisher;
}