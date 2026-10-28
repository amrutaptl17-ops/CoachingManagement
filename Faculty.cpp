#include "Faculty.h"

// Faculty constructor
Faculty::Faculty(int id, string name,
                 string subject, double salary)
    : Person(id, name) {

    this->subject = subject;
    this->salary = salary;
}

// Display faculty details
void Faculty::display() const {
    Person::display();

    cout << "Subject: " << subject
         << "\nSalary: Rs. " << calculateSalary()
         << endl;
}

// Calculate salary
double Faculty::calculateSalary() const {
    return salary;
}

// Function overloading
void Faculty::display(bool showSalary) const {
    Person::display();

    cout << "Subject: " << subject;

    if (showSalary) {
        cout << "\nSalary: Rs. " << calculateSalary();
    }

    cout << endl;
}