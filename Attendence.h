
#ifndef ATTENDENCE_H
#define ATTENDENCE_H

#include <string>
#include <vector>

using namespace std;

struct AttendanceRecord {
    int studentId;
    string date;
    string status;
};

class AttendanceManager {
private:
    vector<AttendanceRecord> records;

public:
    void loadAttendance();
    void addAttendance(int studentId, string date, string status);
    void displayAttendance() const;
};

#endif
