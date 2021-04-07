//
// Created by dcl on 4/6/2021.
//

#include "checkingaccount.h"

// account: base class, super class
// CheckingAccount: derived class, sub-class
banking::CheckingAccount::CheckingAccount(const std::string &iban, double balance, double overdraftAmount) :
        account(iban, balance),
        // account::account(), // implicit
        overdraftAmount(overdraftAmount) {
    // constructor
}

double banking::CheckingAccount::getOverdraftAmount() const {
    return overdraftAmount;
}

void banking::CheckingAccount::setOverdraftAmount(double overdraftAmount) {
    CheckingAccount::overdraftAmount = overdraftAmount;
}

double banking::CheckingAccount::withdraw(const double amount, bool withdrawAvailable) {
    // validation
    if (amount <= 0.0) return 0.0;
    // business rule
    if (!withdrawAvailable && amount > (this->balance + this->overdraftAmount)) return 0.0;
    // business logic
    if (withdrawAvailable && amount > (this->balance + this->overdraftAmount)) {
        double value = this->balance + this->overdraftAmount;
        this->balance = -this->overdraftAmount;
        return value;
    }
    this->balance = this->balance - amount;
    return amount;
}
