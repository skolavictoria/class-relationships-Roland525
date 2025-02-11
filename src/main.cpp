#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Department.h"
#include <iostream>

using namespace std;

int main() {

    Department department("Science Department");

    Student* student1 = new Student("John Doe", 20, 1);
    Student* student2 = new Student("Jane Doe", 22, 2);

    Professor* professor1 = new Professor("Dr. Smith", 45, 101);

    Course* course1 = new Course("Math 101", 301);
    Course* course2 = new Course("Physics 101", 302);
    Course* course3 = new Course("Chemistry 101", 303);

    student1->enrollCourse(course1);
    student1->enrollCourse(course2);
    student2->enrollCourse(course2);

    course1->addStudent(student1);
    course2->addStudent(student2);

    professor1->assignCourse(course1);
    professor1->assignCourse(course3);

    department.addProfessor(professor1);
    department.addCourse(course1);
    department.addCourse(course2);
    department.addCourse(course3);

    student1->displayInfo();
    student1->displayCourses();
    cout << endl;

    professor1->displayInfo();
    professor1->displayAssignedCourses();
    cout << endl;

    department.displayProfessorsAndCourses();

    return 0;
}
