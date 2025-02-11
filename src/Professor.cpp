#include "Professor.h"
#include "Course.h"
#include <iostream>

using namespace std;

Professor::Professor(std::string name, int age, int employeeID)
    : Person(name, age), employeeID(employeeID) {}

void Professor::assignCourse(Course* course) {
    teachingCourses.push_back(course);
}

void Professor::displayAssignedCourses() {
    std::cout << "Assigned Courses:" << std::endl;
    for (Course* course : teachingCourses) {
        std::cout << "- " << course->courseName << std::endl;
    }
}

void Professor::displayInfo() {
    std::cout << "Professor: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}
