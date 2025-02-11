#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Department.h"

using namespace std;

int main() {
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course*> courses;
    Department department("Programming Department");

    int user = 0;
    while (user != 10) {
        cout << "\n1 - Show info\n2 - Modify info\n10 - Exit\nChoose: ";
        cin >> user;

        if (user == 1) { // Вывод информации
            cout << "1 - Students\n2 - Professors\n3 - Department\nChoose: ";
            cin >> user;

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
        }

        if (user == 2) { // Изменение данных
            cout << "1 - Add Student\n2 - Add Professor\n3 - Add Course\n4 - Enroll Student in Course\n5 - Assign Professor to Course\nChoose: ";
            cin >> user;

            if (user == 1) { // Добавить студента
                string name;
                int age, id;
                cout << "Enter student name: "; cin >> name;
                cout << "Enter age: "; cin >> age;
                cout << "Enter student ID: "; cin >> id;
                students.push_back(new Student(name, age, id));
            } 
            else if (user == 2) { // Добавить профессора
                string name;
                int age, id;
                cout << "Enter professor name: "; cin >> name;
                cout << "Enter age: "; cin >> age;
                cout << "Enter employee ID: "; cin >> id;
                professors.push_back(new Professor(name, age, id));
            } 
            else if (user == 3) { // Добавить курс
                string courseName;
                int courseID;
                cout << "Enter course name: "; cin >> courseName;
                cout << "Enter course ID: "; cin >> courseID;
                courses.push_back(new Course(courseName, courseID));
            } 
            else if (user == 4) { // Записать студента на курс
                cout << "Select student ID:\n";
                for (int i = 0; i < students.size(); i++)
                    cout << students[i]->studentID << ": " << students[i]->name << "\n";
                int studentID, courseID;
                cin >> studentID;

                cout << "Select course ID:\n";
                for (int i = 0; i < courses.size(); i++)
                    cout << courses[i]->courseID << ": " << courses[i]->courseName << "\n";
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
            else if (user == 5) { // Назначить курс профессору
                cout << "Select professor ID:\n";
                for (int i = 0; i < professors.size(); i++)
                    cout << professors[i]->employeeID << ": " << professors[i]->name << "\n";
                int professorID, courseID;
                cin >> professorID;

                cout << "Select course ID:\n";
                for (int i = 0; i < courses.size(); i++)
                    cout << courses[i]->courseID << ": " << courses[i]->courseName << "\n";
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
    }
    return 0;
}
