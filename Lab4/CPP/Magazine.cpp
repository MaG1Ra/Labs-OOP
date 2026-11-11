/**
 * \file Magazine.cpp
 * \brief Реализация класса Magazine.
 */
#include "../HPP/Magazine.h"

/**
 * \brief Конструктор с параметрами.
 * \param title_       Название.
 * \param isbn_        ISBN.
 * \param pages_       Количество страниц.
 * \param publisher_   Издательство.
 * \param issueNumber_ Номер выпуска.
 */
Magazine::Magazine(const std::string& title_, const std::string& isbn_, int pages_, const std::string&publisher_, int issueNumber_)
    : Publication(title_,isbn_), PrintedPublication(title_, isbn_, pages_, publisher_), issueNumber(issueNumber_) {}

/**
 * \brief Конструктор копирования.
 * \param other Копируемый журнал.
 */
Magazine::Magazine(const Magazine& other) : Publication(other), PrintedPublication(other), issueNumber(other.issueNumber) {}

/**
 * \brief Оператор присваивания.
 * \param other Присваиваемый журнал.
 * \return Ссылка на *this.
 */
Magazine &Magazine::operator=(const Magazine& other) {
    if (this != &other) {
        PrintedPublication::operator=(other);
        issueNumber = other.issueNumber;
    }
    return *this;
}
/// \brief Деструктор.
Magazine::~Magazine() {}

/// \brief Возвращает номер выпуска.
/// \return Номер выпуска.
int Magazine::getIssueNumber() const {
    return issueNumber;
}

/// \brief Печатает в cout строку <tt>[Magazine] ... | описание</tt>.
void Magazine::printInfo() const {
    std::cout << *this << " | " << getInfo() << '\n';
}