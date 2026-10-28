#ifndef FEEMANAGEMENT_H
#define FEEMANAGEMENT_H

#include "FeePayment.h"
#include <vector>
using namespace std;

class FeeManagement {
private:
    vector<FeePayment> payments;

public:
    void loadPayments();
    void addPayment(const FeePayment& payment);
    void displayPayments();

    double getTotalPaid(int studentId) const;
    double getPendingFee(int studentId, double totalFee) const;
};

#endif