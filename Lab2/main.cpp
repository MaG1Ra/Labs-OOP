#include "Student.h"

/**
 * @file main.cpp
 * @brief Главная программа тестирования класса Student
 *
 * Программа демонстрирует функциональность класса Student:
 * - Создание объектов различными способами
 * - Корректные операции
 * - Некорректные операции и обработка ошибок
 * - Независимость объектов
 * - Использование статического счётчика
 */

/**
 * @brief Функция main - точка входа программы
 * @return 0 при успешном завершении
 *
 * Тестирует класс Student в следующем порядке:
 * 1. Создание объектов (default, параметризованный, копирования)
 * 2. Вывод начального состояния
 * 3. Выполнение корректных операций (birthday, changeGrade, nextCourse)
 * 4. Выполнение некорректных операций (граничные значения)
 * 5. Проверка независимости объектов
 * 6. Итоговый вывод счётчика
 */
int main() {
    std::cout << "Creating class objects\n";
    Student student;
    Student student1({"Sanya", "Papirys", "Olegovich"}, 18, 1, 3.5);
    Student student2(student1);
    std::cout << "Initial state output\n";
    student1.print();
    std::cout << "\n";
    student2.print();
    std::cout << "\n";
    student.print();
    std::cout << "\nPerforming correct operations\n";
    student1.birthday();
    student1.changeGrade(4.5);
    student1.nextCourse();
    student1.print();
    std::cout << "\n";
    student2.print();
    std::cout << "\nPerforming incorrect operations\n";
    Student student3({"Vovka", "Brigada", "Olegovich"}, 100, 6, 5);
    student3.print();
    student3.birthday();
    student3.changeGrade(6);
    student3.nextCourse();
    student3.print();
    std::cout << "\nRepeated state output\n";
    student1.print();
    std::cout << "\n";
    student2.print();
    std::cout << "\n";
    student3.print();
    std::cout << "\nChecking object independence\n";
    student1.print();
    std::cout << "\n";
    student2.print();
    std::cout << "\n";
    student1.birthday();
    student1.changeGrade(4.3);
    student1.nextCourse();
    student1.print();
    std::cout << "\n";
    student2.print();
    std::cout << Student::counter << "\n";
    system("pause");
    return 0;
}