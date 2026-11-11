/**
 * \file EBook.h
 * \brief Объявление класса EBook.
 */
#ifndef LAB4_EBOOK_H
#define LAB4_EBOOK_H
#include "DigitalPublication.h"

/**
 * \class EBook
 * \brief Класс: электронная книга.
 *
 * Наследует данные и поведение \ref DigitalPublication (размер файла, формат)
 * и реализует printInfo().
 *
 */
class EBook : public DigitalPublication {
public:
    /**
     * \brief Конструктор с параметрами.
     * \param title_    Название.
     * \param isbn_     ISBN.
     * \param fileSize_ Размер файла в КБ.
     * \param format_   Формат файла.
     */
    EBook(const std::string& title_, const std::string& isbn_, int fileSize_, const std::string& format_);

    /**
     * \brief Конструктор копирования.
     * \param other Копируемая электронная книга.
     */
    EBook(const EBook& other);

    /**
     * \brief Оператор присваивания.
     * \param other Присваиваемая электронная книга.
     * \return Ссылка на текущий объект (*this).
     */
    EBook& operator=(const EBook& other);

    /// \brief Деструктор.
    ~EBook() override;

    /**
     * \brief Возвращает название типа.
     * \return Строка "EBook".
     */
    std::string getType() const override {
        return "EBook";
    }

    /// \brief Выводит информацию об электронной книге.
    void printInfo() const override;
};
#endif //LAB4_EBOOK_H
