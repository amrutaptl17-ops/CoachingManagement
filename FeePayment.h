#ifndef FEEPAYMENT_H
#define FEEPAYMENT_H

#include <string>
using namespace std;

class FeePayment {
private:
    int studentId;
    double amount;
    string paymentDate;

public:
    FeePayment(int studentId, double amount, string paymentDate);

    int getStudentId() const;
    double getAmount() const;
    string getPaymentDate() const;

    void displayPayment() const;
};

#endif