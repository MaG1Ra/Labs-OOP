/**
 * \file Book.h
 * \brief Объявление класса Book.
 */
#ifndef LAB4_BOOK_H
#define LAB4_BOOK_H
#include "PrintedPublication.h"

/**
 * \class Book
 * \brief Класс: печатная книга.
 *
 * Расширяет \ref PrintedPublication полем «автор» и реализует printInfo(),
 * поэтому является неабстрактным. Служит одной из баз для \ref HybridBook.
 *
 */
class Book : public PrintedPublication {
    std::string author;     ///< Автор книги.
public:
    /**
     * \brief Конструктор с параметрами.
     * \param title_     Название.
     * \param isbn_      ISBN.
     * \param pages_     Количество страниц.
     * \param publisher_ Издательство.
     * \param author_    Автор.
     */
    Book(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_, const std::string& author_);

    /**
     * \brief Конструктор копирования.
     * \param other Копируемая книга.
     */
    Book(const Book& other);

    /**
     * \brief Оператор присваивания.
     * \param other Присваиваемая книга.
     * \return Ссылка на текущий объект (*this).
     */
    Book& operator=(const Book& other);

    /// \brief Деструктор.
    ~Book() override;

    /// \brief Возвращает автора книги.
    /// \return Имя автора.
    std::string getAuthor() const;

    /**
     * \brief Возвращает описание книги.
     * \return Строка вида <tt>Author: ..., Printed: ..., N pages</tt>.
     * \details Переопределяет PrintedPublication::getInfo(), добавляя автора.
     */
    std::string getInfo() const override {
        return "Author: " + author + ", " + PrintedPublication::getInfo();
    }

    /**
     * \brief Возвращает название типа.
     * \return Строка "Book".
     */
    std::string getType() const override {
        return "Book";
    }

    /// \brief Выводит информацию о книге.
    void printInfo() const override;
};
#endif //LAB4_BOOK_H
