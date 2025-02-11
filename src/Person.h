#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
public:
    int age;
    std::string name;

    Person(std::string name, int age);
    void displayInfo();
};

#endif
