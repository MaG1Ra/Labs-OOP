#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H
#include <iostream>
#include <string>
class Student {
    std::string name;
    int age;
    int course;
    double avg_grade;
public:
    static int counter;
    Student();
    Student(std::string& name_, int age_, int course_, double avg_grade_);
    Student(const Student &other);

    ~Student();
};
#endif