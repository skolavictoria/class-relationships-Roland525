#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Professor.h"
#include "Course.h"
#include <vector>

class Department {
public:
    std::string departmentName;
    std::vector<Professor*> professors;
    std::vector<Course*> courses;

    Department(std::string departmentName);
    void addProfessor(Professor* professor);
    void addCourse(Course* course);
    void displayProfessorsAndCourses();
};

#endif
