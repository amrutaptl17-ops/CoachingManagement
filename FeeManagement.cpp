#include "FeeManagement.h"
#include <iostream>
#include <fstream>
using namespace std;

void FeeManagement::loadPayments() {
    ifstream file("payments.txt");

    int id;
    double amount;
    string date;

    while (file >> id >> amount >> date) {
        payments.push_back(FeePayment(id, amount, date));
    }

    file.close();
}

void FeeManagement::addPayment(const FeePayment& payment) {
    payments.push_back(payment);

    ofstream file("payments.txt", ios::app);

    file << payment.getStudentId() << " "
         << payment.getAmount() << " "
         << payment.getPaymentDate() << endl;

    file.close();

    cout << "Payment added successfully!" << endl;
}

void FeeManagement::displayPayments() {
    for (const FeePayment& payment : payments) {
        payment.displayPayment();
        cout << "-------------------" << endl;
    }
}

double FeeManagement::getTotalPaid(int studentId) const {
    double total = 0;

    for (const FeePayment& payment : payments) {
        if (payment.getStudentId() == studentId) {
            total += payment.getAmount();
        }
    }

    return total;
}

double FeeManagement::getPendingFee(int studentId,
                                    double totalFee) const {
    double paid = getTotalPaid(studentId);

    if (paid >= totalFee) {
        return 0;
    }

    return totalFee - paid;
}