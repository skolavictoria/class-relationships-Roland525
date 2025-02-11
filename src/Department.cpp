#include "Department.h"
#include "Student.h"
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
    cout << "Department: " << departmentName << endl;
    cout << "Professors:" << endl;

    for (Professor* professor : professors) {
        cout << "- " << professor->name << endl;
        if (!professor->teachingCourses.empty()) {
            cout << "  Assigned Courses:" << endl;
            for (Course* course : professor->teachingCourses) {
                cout << "  - " << course->courseName << endl;
            }
        }
    }

    cout << "Courses:" << endl;
    for (Course* course : courses) {
        if (course->students.empty()) continue;
        cout << "- " << course->courseName << endl;
        cout << "  Enrolled Students:" << endl;
        for (Student* student : course->students) {
            cout << "  - " << student->name << endl;
        }
    }
}
