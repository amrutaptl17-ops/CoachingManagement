#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    int id;
    string name;

public:
    Person(int id, string name);

    virtual void display() const;

    int getId() const;

    bool operator==(const Person& p) const;
};

// Derived class
class Student : public Person {
private:
    string course;
    double fees;

public:
    Student(int id, string name, string course, double fees);

    void display() const override;

    double calculateFees() const;

    void display(bool showFees) const;
};

// Template function
template <class T>
void showValue(T value) {
    cout << value << endl;
}

#endif