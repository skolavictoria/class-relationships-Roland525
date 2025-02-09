#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person{
    public:
        int age;
        string name;
};

class Student : public Person{
    public:ж
        int studentID;

};ж

class Professor : public Person{
    public:
        int employeeID;ж
};

class Course{
    public:
        int courseID;
        string courseName;
};

class Department{
    public:
        string departmentName;

};

