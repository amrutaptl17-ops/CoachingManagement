#include "Person.h"
#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>

int main() {
    vector<Student> students;

    // Load saved students from file
    ifstream file("students.txt");

    int id;
    string name, course;
    double fees;

    while (file >> id) {
        file.ignore();
        getline(file, name, '|');
        getline(file, course, '|');
        file >> fees;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        students.emplace_back(id, name, course, fees);
    }

    file.close();

    int choice;

    do {
        cout << "\n===== COACHING MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
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
            if (choice == 1) {
                int id;
                string name, course;
                double fees;

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

                // Save student to file
                ofstream outFile("students.txt", ios::app);

                if (!outFile)
                    throw runtime_error("Unable to open file!");

                outFile << id << " "
                        << name << "|"
                        << course << "|"
                        << fees << endl;

                outFile.close();

                cout << "\nStudent added successfully!\n";
            }

            else if (choice == 2) {
                if (students.empty()) {
                    cout << "\nNo students available.\n";
                }

                for (const Student& s : students) {
                    s.display();
                }
            }

            else if (choice == 3) {
                int searchId;

                cout << "Enter Student ID: ";
                cin >> searchId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Student search(searchId, "", "", 0);

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

            else if (choice == 4) {
                cout << "\nThank you!\n";
            }

            else {
                cout << "\nInvalid choice!\n";
            }
        }

        catch (const exception& e) {
            cout << "\nError: " << e.what() << endl;
        }

    } while (choice != 4);

    // Template demonstration
    showValue<string>("Coaching Management System");

    return 0;
}