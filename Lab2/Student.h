#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H
#include <iostream>
#include <string>
/**
 * @brief Класс для представления студента в системе управления студентами.
 *
 * Класс Student моделирует студента с личными данными и академической информацией.
 * Класс обеспечивает корректность данных через проверку инвариантов.
 *
 * @details
 * Инварианты класса:
 * - Имя не должно быть пусто (если пусто, устанавливается "Unknown")
 * - Возраст должен быть в диапазоне [16, 100]
 * - Средняя оценка должна быть в диапазоне [0, 5]
 * - Номер курса должен быть в диапазоне [1, 6]
 *
 * @note Класс содержит статический счётчик для отслеживания активных объектов.
 * @version 1.0
 */
class FullName {
    std::string name;
    std::string surname;
    std::string patronymic;
    public:
    FullName(std::string name_, std::string surname_, std::string patronymic_);

    std::string getFullName() const;
};

class Student {
    /// Имя студента
    FullName full_name;
    /// Возраст студента
    int age;
    /// Курс студента
    int course;
    /// Средние оценки студента
    double avg_grade;
public:
    static int counter;

    /// @brief Конструктор по умолчанию (Имя: "Unknown", Возраст: 18, Курс: 1, Оценка: 0)
    Student();

    /**
     * @brief Параметризованный конструктор с проверкой данных
     * @param name_ Имя студента (если пусто -> "Unknown")
     * @param age_ Возраст (если не [16,100] -> 18)
     * @param course_ Курс (если не [1,6] -> 1)
     * @param avg_grade_ Оценка (если не [0,5] -> 0)
     * @warning При некорректных данных выводится ошибка и устанавливаются дефолты
     * @post counter++
    */
    Student(FullName fullname_, int age_, int course_, double avg_grade_);

    /**
     * @brief Конструктор копирования
     * @param other Студент для копирования
     * @post counter++
     */
    Student(const Student &other);

    /// @brief Деструктор (counter--)
    ~Student();

    /// @brief Получить возраст @return Возраст в годах
    int getAge() const;

    /// @brief Получить среднюю оценку @return Оценка [0,5]
    double getAvgGrade() const;

    /// @brief Получить номер курса @return Курс [1,6]
    int getCourse() const;

    /**
     * @brief День рождения - увеличить возраст на 1
     * @warning Если возраст > 100, остаётся 100 с ошибкой
     * @post age <= 100
     */
    void birthday();

    /**
     * @brief Перевести на следующий курс
     * @warning Если курс > 6, остаётся 6 с ошибкой
     * @post course <= 6
     */
    void nextCourse();

    /**
     * @brief Изменить среднюю оценку
     * @param new_grade Новая оценка [0,5]
     * @warning Если некорректна, ошибка и изменение НЕ происходит
     * @post avg_grade изменяется только если [0,5]
     */
    void changeGrade(double new_grade);

    /// @brief Вывести всю информацию о студенте
    void print() const;
};
#endif