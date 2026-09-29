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

    std::string getName() const;
    int getAge() const;
    double getAvgGrade() const;
    int getCourse() const;

    void birthday();
    void nextCourse();
    void changeGrade(double new_grade);
    void print() const;
};
#endif