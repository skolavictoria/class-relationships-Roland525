#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(std::string courseName, int courseID)
    : courseName(courseName), courseID(courseID) {}

void Course::addStudent(Student* student) {
    students.push_back(student);
}

void Course::displayEnrolledStudents() {
    std::cout << "Enrolled Students:" << std::endl;
    for (Student* student : students) {
        std::cout << "- " << student->name << std::endl;
    }
}
