#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;

Student::Student(string name, int age, int studentID) 
    : Person(name, age), studentID(studentID) {}

void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
}

void Student::displayCourses() {
    cout << name << " added in:\n";
    for (Course* course : enrolledCourses) {
        cout << course->courseName << endl;
    }
}
