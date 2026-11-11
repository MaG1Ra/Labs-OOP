/**
 * \file HybridBook.h
 * \brief Объявление класса HybridBook.
 */
#ifndef LAB4_HYBRIDBOOK_H
#define LAB4_HYBRIDBOOK_H
#include "DigitalPublication.h"
#include "Book.h"

/**
 * \class HybridBook
 * \brief Класс: книга, существующая и в печатном, и в электронном виде.
 *
 * Демонстрирует множественное наследование: наследуется одновременно от
 * \ref Book и \ref DigitalPublication. Обе ветви происходят от Publication,
 * но благодаря виртуальному наследованию
 * подобъект Publication в объекте единственный.
 *
 * Конструкторы HybridBook явно инициализируют виртуальную базу Publication.
 * Функции getTitle(), getISBN(),
 * getInfo() переопределены, потому что в обеих базовых ветвях они уже
 * переопределены по-разному.
 */
class HybridBook : public Book, public DigitalPublication {
public:
    /**
     * \brief Конструктор с параметрами.
     * \param title_     Название.
     * \param isbn_      ISBN.
     * \param pages_     Количество страниц печатной версии.
     * \param publisher_ Издательство.
     * \param author_    Автор.
     * \param fileSize_  Размер электронной версии в КБ.
     * \param format_    Формат электронной версии.
     */
    HybridBook(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_,const std::string& author_, int fileSize_, const std::string& format_);

    /**
     * \brief Конструктор копирования.
     * \param other Копируемая гибридная книга.
     */
    HybridBook(const HybridBook& other);

    /**
     * \brief Оператор присваивания.
     * \param other Присваиваемая гибридная книга.
     * \return Ссылка на текущий объект (*this).
     * \details Присваивает обе базовые части.
     */
    HybridBook& operator=(const HybridBook& other);

    /// \brief Деструктор.
    ~HybridBook() override;

    /**
     * \brief Возвращает название издания.
     * \return Название.
     * \details Переопределение разрешает неоднозначность между двумя базами.
     */
    std::string getTitle() const override;

    /**
     * \brief Возвращает ISBN издания.
     * \return ISBN.
     * \details Переопределение разрешает неоднозначность между двумя базами.
     */
    std::string getISBN() const override;

    /**
     * \brief Возвращает полное описание гибридной книги.
     * \return Описание печатной части, затем <tt>"; electronic version: "</tt>
     *         и описание электронной части.
     */
    std::string getInfo() const override{
        return Book::getInfo() + "; electronic version: " + DigitalPublication::getInfo();
    }

    /**
     * \brief Возвращает название типа.
     * \return Строка "HybridBook".
     */
    std::string getType() const override {
        return "HybridBook";
    }

    /// \brief Выводит информацию о гибридной книге в стандартный поток.
    void printInfo() const override;
};
#endif //LAB4_HYBRIDBOOK_H
