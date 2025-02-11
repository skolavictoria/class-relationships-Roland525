#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"
#include <vector>

class Course;

class Student : public Person {
public:
    int studentID;
    std::vector<Course*> enrolledCourses;

    Student(std::string name, int age, int studentID);
    void enrollCourse(Course* course);
    void displayCourses();
};

#endif
