#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Department.h"

using namespace std;

int main() {
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course*> courses;
    Department department("Programming");

    students.push_back(new Student("Artem", 12, 1));
    students.push_back(new Student("Tomas", 52, 2));

    professors.push_back(new Professor("Juris", 90, 3));
    professors.push_back(new Professor("Barba", 9, 4));

    courses.push_back(new Course("Programming", 5));
    courses.push_back(new Course("Algoritmi", 6));

    students[0]->enrollCourse(courses[0]);
    students[1]->enrollCourse(courses[1]);

    courses[0]->addStudent(students[0]);
    courses[1]->addStudent(students[1]);

    professors[0]->assignCourse(courses[0]);
    professors[1]->assignCourse(courses[1]);

    department.addProfessor(professors[0]);
    department.addProfessor(professors[1]);
    department.addCourse(courses[0]);
    department.addCourse(courses[1]);

    int user = 0;
    while (user != 10) {
        cout << endl;
        cout << "(1) Show students" << endl;
        cout << "(2) Show professors" << endl;
        cout << "(3) Show department" << endl;
        cout << "(4) Add student" << endl;
        cout << "(5) Add professor" << endl;
        cout << "(6) Add course" << endl;
        cout << "(7) Enroll student in course" << endl;
        cout << "(8) Assign professor to course" << endl;
        cout << "(10) Exit" << endl;
        cin >> user;
        cout << endl;

        if (user == 1) {
            for (int i = 0; i < students.size(); i++) {
                students[i]->displayInfo();
                students[i]->displayCourses();
            }
        } 
        else if (user == 2) {
            for (int i = 0; i < professors.size(); i++) {
                professors[i]->displayInfo();
                professors[i]->displayAssignedCourses();
            }
        } 
        else if (user == 3) {
            department.displayProfessorsAndCourses();
        }
        else if (user == 4) {
            string name;
            int age, id;

            cout << "Student name: ";
            cin >> name;

            cout << "Age: ";
            cin >> age;

            cout << "Student id: ";
            cin >> id;

            students.push_back(new Student(name, age, id));
        } 
        else if (user == 5) {
            string name;
            int age, id;

            cout << "Professor name: ";
            cin >> name;

            cout << "Age: ";
            cin >> age;

            cout << "Employee id: ";
            cin >> id;

            professors.push_back(new Professor(name, age, id));
        } 
        else if (user == 6) {
            string courseName;
            int courseID;

            cout << "Course name: ";
            cin >> courseName;

            cout << "Course id: ";
            cin >> courseID;

            courses.push_back(new Course(courseName, courseID));
        } 
        else if (user == 7) {
            cout << "Student id:" << endl;
            for (int i = 0; i < students.size(); i++) {
                cout << students[i]->studentID << ": " << students[i]->name << endl;
            }

            int studentID, courseID;
            cin >> studentID;

            cout << "Course id:" << endl;
            for (int i = 0; i < courses.size(); i++) {
                cout << courses[i]->courseID << ": " << courses[i]->courseName << endl;
            }

            cin >> courseID;

            Student* selectedStudent = 0;
            Course* selectedCourse = 0;

            for (int i = 0; i < students.size(); i++) {
                if (students[i]->studentID == studentID) {
                    selectedStudent = students[i];
                }
            }

            for (int i = 0; i < courses.size(); i++) {
                if (courses[i]->courseID == courseID) {
                    selectedCourse = courses[i];
                }
            }

            if (selectedStudent && selectedCourse) {
                selectedStudent->enrollCourse(selectedCourse);
                selectedCourse->addStudent(selectedStudent);
            }
        } 
        else if (user == 8) {
            cout << "Professor id:" << endl;
            for (int i = 0; i < professors.size(); i++) {
                cout << professors[i]->employeeID << ": " << professors[i]->name << endl;
            }

            int professorID, courseID;
            cin >> professorID;

            cout << "Course id:" << endl;
            for (int i = 0; i < courses.size(); i++) {
                cout << courses[i]->courseID << ": " << courses[i]->courseName << endl;
            }

            cin >> courseID;

            Professor* selectedProfessor = 0;
            Course* selectedCourse = 0;

            for (int i = 0; i < professors.size(); i++) {
                if (professors[i]->employeeID == professorID) {
                    selectedProfessor = professors[i];
                }
            }

            for (int i = 0; i < courses.size(); i++) {
                if (courses[i]->courseID == courseID) {
                    selectedCourse = courses[i];
                }
            }

            if (selectedProfessor && selectedCourse) {
                selectedProfessor->assignCourse(selectedCourse);
            }
        }
    }
    
    return 0;
}
