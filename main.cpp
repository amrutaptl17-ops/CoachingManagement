
#include "Person.h"
#include "Faculty.h"
#include "FeePayment.h"
#include "FeeManagement.h"
#include "Attendence.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <stdexcept>

using namespace std;

int main() {
    vector<Student> students;
    vector<Faculty> faculties;

    FeeManagement feeManager;
    feeManager.loadPayments();

    AttendanceManager attendanceManager;
    attendanceManager.loadAttendance();

    int id;
    string name, course, subject, date;
    double fees, salary, amount;

    // Load saved students
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

    // Load saved faculty
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
        cout << "7. Add Fee Payment\n";
        cout << "8. Display Fee Payments\n";
        cout << "9. Check Pending Fee\n";
        cout << "10. Mark Attendance\n";
        cout << "11. Display Attendance\n";
        cout << "12. Exit\n";
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

            // Add Fee Payment
            else if (choice == 7) {
                cout << "Enter Student ID: ";
                cin >> id;

                cout << "Enter Amount Paid: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Payment Date (DD-MM-YYYY): ";
                getline(cin, date);

                if (id <= 0 || amount <= 0)
                    throw invalid_argument("Invalid payment details!");

                FeePayment payment(id, amount, date);
                feeManager.addPayment(payment);
            }

            // Display Fee Payments
            else if (choice == 8) {
                feeManager.displayPayments();
            }

            // Check Pending Fee
            else if (choice == 9) {
                cout << "Enter Student ID: ";
                cin >> id;

                cout << "Enter Total Course Fee: ";
                cin >> fees;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (id <= 0 || fees < 0)
                    throw invalid_argument("Invalid fee details!");

                cout << "\nTotal Paid: Rs. "
                     << feeManager.getTotalPaid(id) << endl;

                cout << "Pending Fee: Rs. "
                     << feeManager.getPendingFee(id, fees) << endl;
            }

            // Mark Attendance
            else if (choice == 10) {
                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (id <= 0)
                    throw invalid_argument("Invalid Student ID!");

                bool found = false;

                for (const Student& s : students) {
                    if (s.getId() == id) {
                        found = true;
                        break;
                    }
                }

                if (!found)
                    throw invalid_argument("Student not found!");

                cout << "Enter Date (DD-MM-YYYY): ";
                getline(cin, date);

                cout << "Enter Status (P = Present, A = Absent): ";
                char status;
                cin >> status;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (date.empty() ||
                    (status != 'P' && status != 'p' &&
                     status != 'A' && status != 'a')) {
                    throw invalid_argument(
                        "Invalid date or attendance status!");
                }

                string attendanceStatus =
                    (status == 'P' || status == 'p')
                    ? "Present" : "Absent";

                attendanceManager.addAttendance(
                    id, date, attendanceStatus);
            }

            // Display Attendance
            else if (choice == 11) {
                attendanceManager.displayAttendance();
            }

            // Exit
            else if (choice == 12) {
                cout << "\nThank you!\n";
            }

            else {
                cout << "\nInvalid choice!\n";
            }
        }

        catch (const exception& e) {
            cout << "\nError: " << e.what() << endl;
        }

    } while (choice != 12);

    // Template demonstration
    showValue<string>("Coaching Management System");

    return 0;
}
