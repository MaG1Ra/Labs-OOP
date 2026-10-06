#include "Student.h"

/**
 * @file main.cpp
 * @brief Программа тестирования класса
 *
 * Демонстрирует его функциональность:
 * - Создание объектов различными способами
 * - Корректные операции
 * - Некорректные операции и обработка ошибок
 * - Независимость объектов
 * - Использование статического счётчика
 */

/**
 * Тесты выполняются в следующем порядке:
 * 1. Создание объектов
 * 2. Вывод начального состояния
 * 3. Выполнение корректных операций
 * 4. Выполнение некорректных операций
 * 5. Проверка независимости объектов
 * 6. Вывод счётчика
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
    return 0;
}