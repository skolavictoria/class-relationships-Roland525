#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include "Course.h"
#include <vector>

class Course;

class Professor : public Person {
public:
    int employeeID;
    std::vector<Course*> teachingCourses;

    Professor(std::string name, int age, int employeeID);
    void assignCourse(Course* course);
    void displayAssignedCourses();
};

#endif
