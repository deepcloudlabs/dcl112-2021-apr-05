//
// Created by dcl on 4/6/2021.
//

#include "account.h"

using namespace banking;

account::account(const std::string &iban, double balance) {
    this->balance = balance;
    this->iban = iban;
}

const std::string &account::getIban() const {
    return iban;
}

bool account::deposit(const double amount) {
    // validation
    if (amount <= 0.0) return false;
    // business logic
    this->balance = this->balance + amount;
    return true;
}

double account::withdraw(const double amount, bool withdrawAvailable) {
    // validation
    if (amount <= 0.0) return 0.0;
    // business rule
    if (!withdrawAvailable && amount > this->balance) return 0.0;
    // business logic
    if (withdrawAvailable && amount > this->balance) {
        double value = this->balance;
        this->balance = 0;
        return value;
    }
    this->balance = this->balance - amount;
    return amount;

}

std::ostream &banking::operator<<(std::ostream &os, const account &account) {
    os << "account [ iban: " << account.iban << ", balance: " << account.balance << " ]";
    return os;
}
