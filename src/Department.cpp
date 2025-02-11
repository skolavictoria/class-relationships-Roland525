#include "Department.h"
#include <iostream>

using namespace std;

Department::Department(string departmentName)
    : departmentName(departmentName) {}

void Department::addProfessor(Professor* professor) {
    professors.push_back(professor);
}

void Department::addCourse(Course* course) {
    courses.push_back(course);
}

void Department::displayProfessorsAndCourses() {
    cout << "Department: " << departmentName << "Professors: " << endl;
    for (Professor* professor : professors) {
        cout << " " << professor->name << " teaches: ";
        for (Course* course : professor->teachingCourses) {
            cout << course->courseName << " ";
        }
        cout << endl;
    }
}
