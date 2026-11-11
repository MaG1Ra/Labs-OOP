/**
 * \file Publication.cpp
 * \brief Реализация абстрактного базового класса Publication: счётчик, реестр, поиск по ISBN и оператор вывода.
 */
#include "../HPP/Publication.h"
/// Начальное значение счётчика всех изданий.

int Publication::totalCount = 0;
/// Реестр указателей на все существующие издания.
std::vector<Publication*> Publication::registry;

/**
 * \brief Конструктор копирования.
 * \param other Копируемое издание.
 * \details Копирует название и ISBN, увеличивает totalCount, регистрирует копию в registry.
 */
Publication::Publication(const Publication &other) {
    title = other.title;
    isbn = other.isbn;
    totalCount++;
    registry.push_back(this);
}

/**
 * \brief Конструктор с параметрами.
 * \param title_ Название.
 * \param isbn_  ISBN.
 * \details Увеличивает totalCount и регистрирует объект в registry.
 */
Publication::Publication(const std::string &title_, const std::string &isbn_) : title(title_), isbn(isbn_){
    totalCount++;
    registry.push_back(this);
}

/**
 * \brief Оператор присваивания.
 * \param other Присваиваемое издание.
 * \return Ссылка на *this.
 * \details Защищён от самоприсваивания. Счётчик и реестр не меняются.
 */
Publication &Publication::operator=(const Publication &other) {
    if (this != &other) {
        title = other.title;
        isbn = other.isbn;
    }
    return *this;
}

/**
 * \brief Деструктор.
 * \details Находит объект в registry и удаляет его оттуда, затем уменьшает totalCount.
 */
Publication::~Publication() {
    for (auto it = registry.begin(); it != registry.end(); it++) {
        if (*it == this) {
            registry.erase(it);
            break;
        }
    }
    --totalCount;
}

/**
 * \brief Возвращает общее число существующих изданий.
 * \return Значение totalCount.
 */
int Publication::getTotalCount() {
    return totalCount;
}

/**
 * \brief Линейный поиск издания по ISBN в реестре.
 * \param isbn Искомый ISBN.
 * \return Указатель на первое найденное издание или nullptr, если не найдено.
 */
Publication *Publication::findByISBN(std::string isbn) {
    for (Publication* p : registry) {
        if (p->getISBN() == isbn) {
            return p;
        }
    }
    return nullptr;
}

/**
 * \brief Дружественный оператор вывода издания в поток.
 * \param os Поток вывода.
 * \param p  Выводимое издание.
 * \return Ссылка на os.
 * \details Печатает <tt>[Тип] Название (ISBN: ...)</tt>; тип, название и ISBN
 *          берутся через виртуальные функции, поэтому вывод полиморфен.
 */
std::ostream& operator<<(std::ostream& os, const Publication& p) {
    os << "[" << p.getType() << "] " << p.getTitle() << " (ISBN: " << p.getISBN() << ")";
    return os;
}