#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <string>

class Student;

class Course {
public:
    int courseID;
    std::string courseName;
    std::vector<Student*> students;

    Course(std::string courseName, int courseID);
    void addStudent(Student* student);
    void displayEnrolledStudents();
};

#endif
