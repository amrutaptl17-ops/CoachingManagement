
#include "Attendence.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void AttendanceManager::loadAttendance() {
    ifstream file("attendance.txt");
    AttendanceRecord record;

    while (file >> record.studentId) {
        file.ignore(1, '|');
        getline(file, record.date, '|');
        getline(file, record.status);

        records.push_back(record);
    }

    file.close();
}

void AttendanceManager::addAttendance(
    int studentId, string date, string status) {

    AttendanceRecord record = {studentId, date, status};
    records.push_back(record);

    ofstream file("attendance.txt", ios::app);

    if (!file) {
        records.pop_back();
        throw runtime_error("Unable to open attendance file!");
    }

    file << studentId << "|" << date
         << "|" << status << endl;

    file.close();

    cout << "\nAttendance marked successfully!\n";
}

void AttendanceManager::displayAttendance() const {
    if (records.empty()) {
        cout << "\nNo attendance records available.\n";
        return;
    }

    cout << "\n===== ATTENDANCE RECORDS =====\n";

    for (const AttendanceRecord& record : records) {
        cout << "Student ID: " << record.studentId
             << "\nDate: " << record.date
             << "\nStatus: " << record.status
             << "\n------------------------\n";
    }
}
