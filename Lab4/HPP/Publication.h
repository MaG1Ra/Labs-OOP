/**
 * \file Publication.h
 * \brief Объявление абстрактного базового класса.
 *
 * Класс хранит общие данные любого издания, ведёт
 * статический счётчик всех существующих изданий и реестр указателей на них,
 * по которому работает поиск по ISBN.
 */
#ifndef LAB4_PUBLICATION_H
#define LAB4_PUBLICATION_H
#include <string>
#include <vector>
#include <iostream>

/**
 * \class Publication
 * \brief Абстрактный базовый класс всех библиотечных изданий.
 *
 * Класс абстрактный: содержит чисто виртуальные функции getTitle(),
 * getISBN() и printInfo(), поэтому создать объект Publication напрямую нельзя.
 * Конкретное поведение определяют наследники.
 *
 * Каждое создаваемое издание увеличивает счётчик totalCount и добавляется
 * в статический реестр registry; при уничтожении — удаляется из реестра,
 * а счётчик уменьшается.
 *
 * \note Для \ref PrintedPublication и \ref DigitalPublication класс является
 *       виртуальной базой, чтобы в \ref HybridBook
 *       существовал только один подобъект Publication.
 *
 */
class Publication {
protected:
    std::string title;          ///< Название издания.
    std::string isbn;           ///< Стандартный номер книги.
    static int totalCount;      ///< Общее число существующих изданий всех типов.
public:
    /**
     * \brief Возвращает название издания.
     * \return Название издания.
     */
    virtual std::string getTitle() const = 0;

    /**
     * \brief Возвращает ISBN издания.
     * \return Строка с ISBN.
     */
    virtual std::string getISBN() const = 0;

    /**
     * \brief Выводит в стандартный поток краткую информацию об издании.
     */
    virtual void printInfo() const = 0;

    /**
     * \brief Возвращает название типа издания.
     * \return Строка "Publication".
     */
    virtual std::string getType() const {
        return "Publication";
    }

    /**
     * \brief Конструктор копирования.
     * \param other Копируемое издание.
     * \details Копирует название и ISBN, увеличивает счётчик totalCount
     *          и регистрирует новый объект в реестре registry.
     */
    Publication(const Publication& other);

    /**
     * \brief Конструктор с параметрами.
     * \param title_ Название издания.
     * \param isbn_  ISBN издания.
     * \details Увеличивает счётчик totalCount и добавляет объект в реестр registry.
     */
    Publication(const std::string& title_, const std::string& isbn_);

    /**
     * \brief Оператор присваивания.
     * \param other Присваиваемое издание.
     * \return Ссылка на текущий объект (*this).
     * \details Копирует название и ISBN. Счётчик и реестр не меняются,
     *          так как новый объект не создаётся.
     */
    Publication& operator=(const Publication& other);

    /**
     * \brief Виртуальный деструктор.
     * \details Удаляет объект из реестра registry и уменьшает счётчик totalCount.
     *          Виртуальность гарантирует корректное удаление через указатель на базу.
     */
    virtual ~Publication();

    /**
     * \brief Ищет издание по ISBN в статическом реестре.
     * \param isbn ISBN искомого издания.
     * \return Указатель на найденное издание или nullptr, если такого нет.
     */
    static Publication* findByISBN(std::string);

    /**
     * \brief Возвращает общее число существующих изданий.
     * \return Значение статического счётчика totalCount.
     */
    static int getTotalCount();

    /// Реестр указателей на все существующие издания.
    static std::vector<Publication*> registry;

    /**
     * \brief Дружественный оператор вывода издания в поток.
     * \param os Поток вывода.
     * \param p  Выводимое издание.
     * \return Ссылка на поток os (для цепочек вызовов).
     * \details Формат: <tt>[Тип] Название (ISBN: ...)</tt>.
     */
    friend std::ostream& operator<<(std::ostream&, const Publication&);
};
#endif //LAB4_PUBLICATION_H
