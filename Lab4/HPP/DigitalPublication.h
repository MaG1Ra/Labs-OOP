/**
 * \file DigitalPublication.h
 * \brief Объявление класса DigitalPublication.
 */
#ifndef LAB4_DIGITALPUBLICATION_H
#define LAB4_DIGITALPUBLICATION_H
#include "Publication.h"

/**
 * \class DigitalPublication
 * \brief Промежуточный класс иерархии: электронное издание.
 *
 * Добавляет к Publication размер файла и формат. Ведёт собственный
 * статический счётчик электронных изданий digitalCount. Конкретные электронные издания —
 * \ref EBook и \ref HybridBook.
 *
 * Наследуется от Publication.
 *
 */
class DigitalPublication : virtual public Publication {
    int fileSize;                   ///< Размер файла в килобайтах (КБ).
    std::string format;             ///< Формат файла (PDF, EPUB, FB2 и т. д.).
    static int digitalCount;        ///< Число существующих электронных изданий.
public:
    /**
     * \brief Конструктор с параметрами.
     * \param title_    Название издания.
     * \param isbn_     ISBN издания.
     * \param filesize_ Размер файла в КБ.
     * \param format_   Формат файла.
     * \details Увеличивает счётчик digitalCount.
     */
    DigitalPublication(const std::string&title_, const std::string&isbn_, int filesize_, const std::string& format_);

    /**
     * \brief Конструктор копирования.
     * \param other Копируемый объект.
     * \details Копия тоже является электронным изданием, поэтому digitalCount увеличивается.
     */
    DigitalPublication(const DigitalPublication& other);

    /**
     * \brief Оператор присваивания.
     * \param other Присваиваемый объект.
     * \return Ссылка на текущий объект (*this).
     * \details Счётчик digitalCount не меняется: новый объект не создаётся.
     */
    DigitalPublication& operator=(const DigitalPublication& other);

    /// \brief Деструктор. Уменьшает счётчик digitalCount.
    ~DigitalPublication() override;

    /// \brief Возвращает название издания.
    /// \return Название.
    std::string getTitle() const override;

    /// \brief Возвращает ISBN издания.
    /// \return ISBN.
    std::string getISBN() const override;

    /// \brief Возвращает размер файла.
    /// \return Размер в КБ.
    int getFileSize() const;

    /// \brief Возвращает формат файла.
    /// \return Строка с форматом.
    std::string getFormat() const;

    /**
     * \brief Возвращает описание электронной части издания.
     * \return Строка вида <tt>Size: N KB, format: F</tt>.
     * \note Виртуальная функция с реализацией по умолчанию; используется
     *       в \ref EBook и \ref HybridBook.
     */
    virtual std::string getInfo() const {
        return "Size: " + std::to_string(fileSize) + " KB, format: " + format;
    }

    /**
     * \brief Возвращает название типа.
     * \return Строка "DigitalPublication".
     */
    std::string getType() const override {
        return "DigitalPublication";
    }

    /**
     * \brief Возвращает число существующих электронных изданий.
     * \return Значение статического счётчика digitalCount.
     */
    static int getDigitalCount();
};
#endif //LAB4_DIGITALPUBLICATION_H
