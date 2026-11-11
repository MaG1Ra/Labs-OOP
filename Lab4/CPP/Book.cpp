/**
 * \file Book.cpp
 * \brief Реализация класса Book (печатная книга).
 */
#include "../HPP/Book.h"

/**
 * \brief Конструктор с параметрами.
 * \param title_     Название.
 * \param isbn_      ISBN.
 * \param pages_     Количество страниц.
 * \param publisher_ Издательство.
 * \param author_    Автор.
 * \details Явно инициализирует виртуальную базу Publication, затем PrintedPublication.
 */
Book::Book(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_, const std::string& author_)
    : Publication(title_, isbn_), PrintedPublication(title_, isbn_, pages_, publisher_), author(author_) {}

/**
 * \brief Конструктор копирования.
 * \param other Копируемая книга.
 */
Book::Book(const Book& other) : Publication(other), PrintedPublication(other), author(other.author) {}

/**
 * \brief Оператор присваивания.
 * \param other Присваиваемая книга.
 * \return Ссылка на *this.
 */
Book& Book::operator=(const Book& other) {
    if (this != &other) {
        PrintedPublication::operator=(other);
        author = other.author;
    }
    return *this;
}

/// \brief Деструктор.
Book::~Book() {}

/// \brief Возвращает автора книги.
/// \return Имя автора.
std::string Book::getAuthor() const {
    return author;
}

/// \brief Печатает в cout строку <tt>[Book] ... | описание</tt>.
void Book::printInfo() const {
    std::cout << *this << " | " << getInfo() << "\n";
}
