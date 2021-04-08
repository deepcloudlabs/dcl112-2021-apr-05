//
// Created by dcl on 4/6/2021.
//

#include "checkingaccount.h"
#include "insufficientbalanceexception.h"

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

void banking::CheckingAccount::withdraw(const double amount) {
    // validation
    if (amount <= 0.0) throw std::runtime_error("amount cannot be negative!");
    // business logic
    if (amount > (this->balance + this->overdraftAmount)) {
        throw banking::InsufficientBalanceException("your balance does not cover the whole amount!");
    }
    this->balance = this->balance - amount;
}
