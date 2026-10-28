#include "Person.h"
#include "Faculty.h"

#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>

int main() {
    vector<Student> students;
    vector<Faculty> faculties;

    int id;
    string name, course, subject;
    double fees, salary;

    // Load saved students from file
    ifstream studentFile("students.txt");

    while (studentFile >> id) {
        studentFile.ignore();

        getline(studentFile, name, '|');
        getline(studentFile, course, '|');

        studentFile >> fees;
        studentFile.ignore(numeric_limits<streamsize>::max(), '\n');

        students.emplace_back(id, name, course, fees);
    }

    studentFile.close();

    // Load saved faculty members from file
    ifstream facultyFile("faculty.txt");

    while (facultyFile >> id) {
        facultyFile.ignore();

        getline(facultyFile, name, '|');
        getline(facultyFile, subject, '|');

        facultyFile >> salary;
        facultyFile.ignore(numeric_limits<streamsize>::max(), '\n');

        faculties.emplace_back(id, name, subject, salary);
    }

    facultyFile.close();

    int choice;

    do {
        cout << "\n===== COACHING MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Add Faculty\n";
        cout << "5. Display Faculty\n";
        cout << "6. Search Faculty\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input!\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            // Add Student
            if (choice == 1) {
                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Student Name: ";
                getline(cin, name);

                cout << "Enter Course: ";
                getline(cin, course);

                cout << "Enter Fees: ";
                cin >> fees;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (id <= 0 || fees < 0)
                    throw invalid_argument("Invalid student details!");

                Student s(id, name, course, fees);

                students.push_back(s);

                ofstream outFile("students.txt", ios::app);

                if (!outFile)
                    throw runtime_error("Unable to open student file!");

                outFile << id << " "
                        << name << "|"
                        << course << "|"
                        << fees << endl;

                outFile.close();

                cout << "\nStudent added successfully!\n";
            }

            // Display Students
            else if (choice == 2) {
                if (students.empty()) {
                    cout << "\nNo students available.\n";
                }

                for (const Student& s : students) {
                    s.display();
                }
            }

            // Search Student
            else if (choice == 3) {
                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Student search(id, "", "", 0);

                bool found = false;

                for (const Student& s : students) {
                    if (s == search) {
                        s.display();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "\nStudent not found!\n";
            }

            // Add Faculty
            else if (choice == 4) {
                cout << "Enter Faculty ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Faculty Name: ";
                getline(cin, name);

                cout << "Enter Subject: ";
                getline(cin, subject);

                cout << "Enter Salary: ";
                cin >> salary;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (id <= 0 || salary < 0)
                    throw invalid_argument("Invalid faculty details!");

                Faculty f(id, name, subject, salary);

                faculties.push_back(f);

                // Save Faculty details to file
                ofstream outFile("faculty.txt", ios::app);

                if (!outFile)
                    throw runtime_error("Unable to open faculty file!");

                outFile << id << " "
                        << name << "|"
                        << subject << "|"
                        << salary << endl;

                outFile.close();

                cout << "\nFaculty added successfully!\n";
            }

            // Display Faculty
            else if (choice == 5) {
                if (faculties.empty()) {
                    cout << "\nNo faculty available.\n";
                }

                for (const Faculty& f : faculties) {
                    f.display();
                }
            }

            // Search Faculty
            else if (choice == 6) {
                cout << "Enter Faculty ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Faculty search(id, "", "", 0);

                bool found = false;

                for (const Faculty& f : faculties) {
                    if (f == search) {
                        f.display();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "\nFaculty not found!\n";
            }

            // Exit
            else if (choice == 7) {
                cout << "\nThank you!\n";
            }

            else {
                cout << "\nInvalid choice!\n";
            }
        }

        catch (const exception& e) {
            cout << "\nError: " << e.what() << endl;
        }

    } while (choice != 7);

    // Template demonstration
    showValue<string>("Coaching Management System");

    return 0;
}