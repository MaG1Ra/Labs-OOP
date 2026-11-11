/**
 * \file PrintedPublication.h
 * \brief Объявление класса PrintedPublication.
 */
#ifndef LAB4_PRINTEDPUBLICATION_H
#define LAB4_PRINTEDPUBLICATION_H
#include "../HPP/Publication.h"

/**
 * \class PrintedPublication
 * \brief Промежуточный класс иерархии: печатное издание.
 *
 * Добавляет к Publication число страниц и издательство. Класс остаётся
 * абстрактным, так как не реализует printInfo(); конкретные печатные издания —
 * \ref Book и \ref Magazine.
 *
 * Наследуется от Publication виртуально (virtual public), чтобы избежать
 * дублирования базы в \ref HybridBook.
 *
 */
class PrintedPublication : virtual public Publication {
protected:
    int pages;                  ///< Количество страниц.
    std::string publisher;      ///< Издательство.
public:
    /**
     * \brief Конструктор с параметрами.
     * \param title_     Название издания.
     * \param isbn_      ISBN издания.
     * \param pages_     Количество страниц.
     * \param publisher  Издательство.
     */
    PrintedPublication(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher);

    /**
     * \brief Конструктор копирования.
     * \param other Копируемый объект.
     */
    PrintedPublication(const PrintedPublication& other);

    /**
     * \brief Оператор присваивания.
     * \param other Присваиваемый объект.
     * \return Ссылка на текущий объект (*this).
     * \details Проверяет самоприсваивание, затем копирует поля базы и собственные поля.
     */
    PrintedPublication& operator=(const PrintedPublication& other);

    /// \brief Деструктор.
    ~PrintedPublication() override;

    /**
     * \brief Возвращает описание печатного издания.
     * \return Строка вида <tt>Printed: Название, N pages</tt>.
     * \note Виртуальная функция с реализацией по умолчанию; \ref Book и
     *       \ref Magazine переопределяют её, дополняя результат этой реализации.
     */
    virtual std::string getInfo() const {
        return "Printed: " + getTitle() + ", " + std::to_string(pages) + " pages";
    }

    /**
     * \brief Возвращает название типа.
     * \return Строка "PrintedPublication".
     */
    std::string getType() const override {
        return "PrintedPublication";
    }

    /// \brief Возвращает название издания.
    /// \return Название.
    std::string getTitle() const override;

    /// \brief Возвращает ISBN издания.
    /// \return ISBN.
    std::string getISBN() const override;

    /// \brief Возвращает количество страниц.
    /// \return Число страниц.
    int getPages() const;

    /// \brief Возвращает издательство.
    /// \return Название издательства.
    std::string getPublisher() const;
};
#endif //LAB4_PRINTEDPUBLICATION_H
