# Coaching Management System

## About the Project
The Coaching Management System is a C++ application developed using Object-Oriented Programming (OOP) concepts. It helps manage students, faculty, fee payments, and student attendance.

## Features
- Add, display, and search students
- Add, display, and search faculty
- Record and display fee payments
- Check pending student fees
- Mark and display student attendance
- Save records using text files
- Handle invalid inputs using exception handling

## Technologies Used
- C++
- C++ Standard Library
- File Handling
- Git and GitHub
- Visual Studio Code

## OOP Concepts Used
- **Inheritance:** Student and Faculty inherit from Person.
- **Polymorphism:** Function overloading is used in the classes.
- **Operator Overloading:** The equality operator (`==`) is overloaded for searching by ID.
- **Templates:** A template function demonstrates generic programming.
- **Exception Handling:** `try`, `catch`, and `throw` handle errors.
- **File Handling:** Text files store records between program runs.

## Project Files
- `main.cpp` — Main menu and program logic
- `Person.h`, `Person.cpp` — Person and Student classes
- `Faculty.h`, `Faculty.cpp` — Faculty management
- `FeePayment.h`, `FeePayment.cpp` — Fee payment records
- `FeeManagement.h`, `FeeManagement.cpp` — Fee management operations
- `Attendence.h`, `Attendence.cpp` — Attendance management

## How to Compile and Run

Compile the project using g++:

```bash
g++ main.cpp Person.cpp Faculty.cpp FeePayment.cpp FeeManagement.cpp Attendence.cpp -o coaching.exe
```

Run on Windows PowerShell:

```powershell
.\coaching.exe
```

## Data Files
The program uses text files to store student, faculty, fee payment, and attendance records.

## Future Improvements
- Subject-wise attendance
- Attendance percentage reports
- Improved input validation
- More detailed fee reports

## Team Project
Developed collaboratively using Git and GitHub.
