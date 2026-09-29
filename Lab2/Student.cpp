#include "Student.h"

int Student::counter = 0;

Student::Student() {
    name = "Unknown";
    age = 18;
    course = 1;
    avg_grade = 0;
    counter++;
}

Student::Student(std::string& name_, int age_, int course_, double avg_grade_) :
name(name_), age(age_), course(course_), avg_grade(avg_grade_) {
    if (name.empty()) {
        name = "Unknown";
        std::cerr << "Error empty name";
    }
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

Student::Student(const Student &other) {
    name = other.name;
    age = other.age;
    course = other.course;
    avg_grade = other.avg_grade;
    counter++;
}

Student::~Student() {
    std::cout << "\nDestructor";
    counter--;
}