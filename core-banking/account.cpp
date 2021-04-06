//
// Created by dcl on 4/6/2021.
//

#include "account.h"

account::account(const std::string &iban, double balance)  {
    this->balance = balance;
    this->iban = iban;
}

const std::string &account::getIban() const {
    return iban;
}

double account::getBalance() const {
    return balance;
}

bool account::deposit(const double amount) {
    // validation
    if (amount<=0.0) return false;
    // business logic
    this->balance = this->balance + amount;
    return true;
}

bool account::withdraw(const double amount) {
    // validation
    if (amount<=0.0) return false;
    // business rule
    if (amount>this->balance) return false;
    // business logic
    this->balance = this->balance - amount;
    return true;
}
