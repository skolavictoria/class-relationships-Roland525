#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course;

class Person {
public:
    int age;
    string name;

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
public:
    int studentID;
    vector<Course*> enrolledCourses;

    void enrollCourse(Course* course) {
        enrolledCourses.push_back(course);
    }

    void displayCourses() {
        cout << name << " added to these courses:" << endl;
        for (int i = 0; i < enrolledCourses.size(); i++) {
            cout << enrolledCourses[i]->courseName << endl;
        }
    }
};

class Professor : public Person {
public:
    int employeeID;
    vector<Course*> teachingCourses;

    void assignCourse(Course* course) {
        teachingCourses.push_back(course);
    }

    void displayAssignedCourses() {
        cout << name << " is teaching these courses:" << endl;
        for (int i = 0; i < teachingCourses.size(); i++) {
            cout << teachingCourses[i]->courseName << endl;
        }
    }
};

class Course {
public:
    int courseID;
    string courseName;
    vector<Student*> students;

    void addStudent(Student* student) {
        students.push_back(student);
        cout << student->name << " added to " << courseName << endl;
    }

    void displayEnrolledStudents() {
        cout << "Students in " << courseName << ":" << endl;
        for (int i = 0; i < students.size(); i++) {
            cout << students[i]->name << endl;
        }
    }
};

class Department {
public:
    string departmentName;
    vector<Professor*> professors;
    vector<Course*> courses;

    void addProfessor(Professor* professor) {
        professors.push_back(professor);
    }

    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void displayProfessorsAndCourses() {
        cout << "Department name: " << departmentName << endl;

        cout << "Professors: " << endl;
        for (int i = 0; i < professors.size(); i++) {
            cout << professors[i]->name << " teaches: ";
            for (int j = 0; j < professors[i]->teachingCourses.size(); j++) {
                cout << professors[i]->teachingCourses[j]->courseName << " ";
            }
            cout << endl;
        }

        cout << "Courses: " << endl;
        for (int i = 0; i < courses.size(); i++) {
            cout << courses[i]->courseName << endl;
        }
    }
};

int main() {
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course*> courses;
    Department department;
    department.departmentName = "Programming Department";

    int user;
    while (user != 10) {
        cout << "(1) Show info" << endl << "(2) Modify info" << endl << "(10) Exit" << endl;
        cin >> user;

        if (user == 1) {
            cout << "(1) Students "<< endl << "(2) Professors" << endl << "(3) Department" << endl;
            cin >> user;

            if (user == 1) { 
                for (int i = 0; i < students.size(); i++) {
                    students[i]->displayInfo();
                    students[i]->displayCourses();
                }
            } else if (user == 2) { 
                for (int i = 0; i < professors.size(); i++) {
                    professors[i]->displayInfo();
                    professors[i]->displayAssignedCourses();
                }
            } else if (user == 3) { 
                department.displayProfessorsAndCourses();
            }
        }

        if (user == 2) {
            cout << "1 - Add Student\n2 - Add Professor\n3 - Add Course\n4 - Enroll Student\n5 - Assign Course to Professor\n6 - Add Professor to Department\n7 - Add Course to Department\nChoose: ";
            cin >> user;

            if (user == 1) {
                Student* s = new Student();
                cout << "Enter name: ";
                cin >> s->name;
                cout << "Enter age: ";
                cin >> s->age;
                cout << "Enter ID: ";
                cin >> s->studentID;
                students.push_back(s);
            } 
            else if (user == 2) {
                Professor* p = new Professor();
                cout << "Enter name: ";
                cin >> p->name;
                cout << "Enter age: ";
                cin >> p->age;
                cout << "Enter ID: ";
                cin >> p->employeeID;
                professors.push_back(p);
            } 
            else if (user == 3) {
                Course* c = new Course();
                cout << "Enter course name: ";
                cin >> c->courseName;
                cout << "Enter course ID: ";
                cin >> c->courseID;
                courses.push_back(c);
            } 
            else if (user == 4) {
                cout << "Select student ID: ";
                int studentID;
                cin >> studentID;
                Student* s = NULL;
                for (int i = 0; i < students.size(); i++) {
                    if (students[i]->studentID == studentID) {
                        s = students[i];
                        break;
                    }
                }

                cout << "Select course ID: ";
                int courseID;
                cin >> courseID;
                Course* c = NULL;
                for (int i = 0; i < courses.size(); i++) {
                    if (courses[i]->courseID == courseID) {
                        c = courses[i];
                        break;
                    }
                }

                if (s != NULL && c != NULL) {
                    s->enrollCourse(c);
                    c->addStudent(s);
                }
            }
        }
    }
    return 0;
}
