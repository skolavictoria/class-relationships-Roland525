#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age);
    virtual void displayInfo();
};

#endif
