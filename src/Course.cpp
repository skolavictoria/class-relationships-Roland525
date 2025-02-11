#include "Course.h"
#include "Student.h"
#include <iostream>

using namespace std;

Course::Course(string courseName, int courseID)
    : courseName(courseName), courseID(courseID) {}

void Course::addStudent(Student* student) {
    students.push_back(student);
    cout << student->name << " added to " << courseName << endl;
}

void Course::displayEnrolledStudents() {
    cout << "Students in " << courseName << ": ";
    for (Student* student : students) {
        cout << " " << student->name << endl;
    }
}
