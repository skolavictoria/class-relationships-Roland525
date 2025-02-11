#include "Person.h"

Person::Person(std::string name, int age) : name(name), age(age) {}

void Person::displayInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}
