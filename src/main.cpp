#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person{
    public:
        int age;
        string name;

    void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person{
    public:
        int studentID;

    vector<Course*> enrolledCourses;

    void enrollCourse(Course* course){

    }
    void displayCourses(){

    }

};

class Professor : public Person{
    public:
        int employeeID;

    vector<Course*> teachingCourses;

    void assignCourse(Course* course){

    }

    void displayAssignedCourses(){

    }
};

class Course{
    public:
        int courseID;
        string courseName;

    vector<Student*> students;

    void addStudent(Student* student){

    }
};

class Department{
    public:
        string departmentName;

    vector<Professor*> professors;
    vector<Course*> courses;

    void addProfessor(Professor* professor){

    }
    void addCourse(Course* course){

    }
    void displayProfessosAndCourses(){

    }
};

int main(){
    int user;
    while(user != 10){
        cout << "Choose option:" << endl << "(1) Display info, " << "(2) Change info " << "(10) Exit" << endl;
        cin >> user;
        if (user == 1){
            user = 0;
            cout << "Choose option: " << endl << "(1) Display student info" << endl << "(2) Display professor info" << endl << "(3) Display depatrment info" << endl;
            cin >> user;
            if (user == 1){
                    displayInfo and displayCourses;

                }
            
            else if(user == 2){
                displayAssignedCourses();
            }
            
            else if(user == 3){
                displayProfessosAndCourses();
            }
        }
    if(user == 2){
        user = 0;
        cout << "Choose option: " << endl << "(1) Add student course " << "(2) Add Professor course " << "(3) Add professor " << "(4) Add course" << endl;

        if(user == 1){
            
        }
    }
    }
};

