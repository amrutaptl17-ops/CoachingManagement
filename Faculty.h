#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>
using namespace std;

class Faculty : public Person {
private:
    string subject;
    double salary;

public:
    Faculty(int id, string name, string subject, double salary);

    void display() const override;

    double calculateSalary() const;

    void display(bool showSalary) const;
};

#endif