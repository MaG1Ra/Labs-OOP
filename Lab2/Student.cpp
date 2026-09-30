/// @file Student.cpp
/// @brief Реализация класса Student
#include "Student.h"

/// Инициализация статического счётчика
int Student::counter = 0;

FullName::FullName(std::string name_, std::string surname_, std::string patronymic_) :
name(name_), surname(surname_), patronymic(patronymic_) {
    if (name.empty()) {
        name = "Unknown";
        std::cout << "Error empty name";
    }
    if (surname.empty()) {
        surname = "Unknown";
        std::cout << "Error empty surname";
    }
    if (patronymic.empty()) {
        patronymic = "Unknown";
        std::cout << "Error empty patronymic";
    }
}

Student::Student() : full_name("Unknown", "Unknown", "Unknown") {

    age = 18;
    course = 1;
    avg_grade = 0;
    counter++;
}

Student::Student(FullName fullname_, int age_, int course_, double avg_grade_) :
full_name(fullname_), age(age_), course(course_), avg_grade(avg_grade_) {
    if ( 16 > age || age > 100 ) {
        age = 18;
        std::cerr << "Error invalid age";
    }
    if ( 0 > course || course > 6 ) {
        course = 1;
        std::cerr << "Error invalid course";
    }
    if ( 0 > avg_grade || avg_grade > 5) {
        avg_grade = 0;
        std::cerr << "Error invalid avg_grade";
    }
    counter++;
}

Student::Student(const Student &other) : full_name(other.full_name) {
    age = other.age;
    course = other.course;
    avg_grade = other.avg_grade;
    counter++;
}

Student::~Student() {
    std::cout << "\nDestructor";
    counter--;
}

std::string FullName::getFullName() const {
    return name + " " + surname + " " + patronymic;
}

int Student::getAge() const {
    return age;
}

int Student::getCourse() const {
    return course;
}

double Student::getAvgGrade() const {
    return avg_grade;
}

void Student::birthday() {
    age++;
    if (age > 100) {
        age = 100;
        std::cout << "\033[31m!!!Error invalid age!!!\n\033[0m";
    }
}

void Student::nextCourse() {
    course++;
    if (course > 6) {
        course = 6;
        std::cout << "\033[31m!!!Error invalid course!!!\n\033[0m";
    }
}

void Student::changeGrade(double new_grade) {
    if (new_grade < 0 || new_grade > 5) {
        std::cout << "\033[31m!!!Error invalid grade!!!\n\033[0m";
        return;
    }
    avg_grade = new_grade;
}

void Student::print() const {
    std::cout << "Full name: " << full_name.getFullName() << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Avg grade: " << avg_grade << "\n";
    std::cout << "Course: " << course << "\n";
}