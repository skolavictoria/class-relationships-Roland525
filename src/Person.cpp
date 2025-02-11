#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(string name, int age) : name(name), age(age) {}

void Person::displayInfo() {
    cout << "Name: " << name << endl << "Age: " << age << endl;
}
