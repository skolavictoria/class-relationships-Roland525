#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;

Student::Student(std::string name, int age, int studentID)
    : Person(name, age), studentID(studentID) {}

void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
}

void Student::displayCourses() {
    std::cout << "Enrolled Courses:" << std::endl;
    for (Course* course : enrolledCourses) {
        std::cout << "- " << course->courseName << std::endl;
    }
}

void Student::displayInfo() {
    std::cout << "Student: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}
