#include "Person.h"

// Person constructor
Person::Person(int id, string name) {
    this->id = id;
    this->name = name;
}

// Display person details
void Person::display() const {
    cout << "\nID: " << id
         << "\nName: " << name << endl;
}

// Get ID
int Person::getId() const {
    return id;
}

// Operator overloading
bool Person::operator==(const Person& p) const {
    return id == p.id;
}

// Student constructor
Student::Student(int id, string name,
                 string course, double fees)
    : Person(id, name) {

    this->course = course;
    this->fees = fees;
}

// Display student details
void Student::display() const {
    Person::display();

    cout << "Course: " << course
         << "\nFees: Rs. " << calculateFees()
         << endl;
}

// Calculate fees
double Student::calculateFees() const {
    return fees;
}

// Function overloading
void Student::display(bool showFees) const {
    Person::display();

    cout << "Course: " << course;

    if (showFees)
        cout << "\nFees: Rs. " << calculateFees();

    cout << endl;
}