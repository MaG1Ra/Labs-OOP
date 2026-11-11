/**
 * \file Magazine.h
 * \brief Объявление класса Magazine.
 */
#ifndef LAB4_MAGAZINE_H
#define LAB4_MAGAZINE_H
#include "PrintedPublication.h"

/**
 * \class Magazine
 * \brief Класс: печатный журнал.
 *
 * Расширяет \ref PrintedPublication номером выпуска и реализует printInfo().
 *
 */
class Magazine : public PrintedPublication {
int issueNumber;            ///< Номер выпуска журнала.
public:
    /**
     * \brief Конструктор с параметрами.
     * \param title_       Название журнала.
     * \param isbn_        ISBN (ISSN) издания.
     * \param pages_       Количество страниц.
     * \param publisher_   Издательство.
     * \param issueNumber  Номер выпуска.
     */
    Magazine(const std::string& title_, const std::string& isbn_, int pages_, const std::string& publisher_, int issueNumber);

    /**
     * \brief Конструктор копирования.
     * \param other Копируемый журнал.
     */
    Magazine(const Magazine& other);

    /**
     * \brief Оператор присваивания.
     * \param other Присваиваемый журнал.
     * \return Ссылка на текущий объект (*this).
     */
    Magazine& operator=(const Magazine& other);

    /// \brief Деструктор.
    ~Magazine() override;

    /// \brief Возвращает номер выпуска.
    /// \return Номер выпуска.
    int getIssueNumber() const;

    /**
     * \brief Возвращает описание журнала.
     * \return Строка вида <tt>Magazine issue №N, Printed: ..., N pages</tt>.
     * \details Переопределяет PrintedPublication::getInfo(), добавляя номер выпуска.
     */
    std::string getInfo() const override {
        return "Magazine issue №" + std::to_string(issueNumber) + ", " + PrintedPublication::getInfo();
    }

    /**
     * \brief Возвращает название типа.
     * \return Строка "Magazine".
     */
    std::string getType() const override {
        return "Magazine";
    }

    /// \brief Выводит информацию о журнале.
    void printInfo() const override;
};
#endif //LAB4_MAGAZINE_H
