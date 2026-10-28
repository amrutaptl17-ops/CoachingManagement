#include "FeePayment.h"
#include <iostream>
using namespace std;

FeePayment::FeePayment(int studentId, double amount,
                       string paymentDate) {
    this->studentId = studentId;
    this->amount = amount;
    this->paymentDate = paymentDate;
}

int FeePayment::getStudentId() const {
    return studentId;
}

double FeePayment::getAmount() const {
    return amount;
}

string FeePayment::getPaymentDate() const {
    return paymentDate;
}

void FeePayment::displayPayment() const {
    cout << "Student ID: " << studentId << endl;
    cout << "Amount Paid: Rs. " << amount << endl;
    cout << "Payment Date: " << paymentDate << endl;
}