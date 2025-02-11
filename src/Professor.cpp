#include "Professor.h"
#include <iostream>

using namespace std;

Professor::Professor(string name, int age, int employeeID)
    : Person(name, age), employeeID(employeeID) {}

void Professor::assignCourse(Course* course) {
    teachingCourses.push_back(course);
}

void Professor::displayAssignedCourses() {
    cout << name << " teaches: ";
    for (Course* course : teachingCourses) {
        cout << course->courseName << endl;
    }
}
