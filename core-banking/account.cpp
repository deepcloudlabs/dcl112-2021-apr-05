//
// Created by dcl on 4/6/2021.
//

#include <iostream>
#include "account.h"

using namespace banking;

int account::numOfAccounts = 0; // definition

account::account(const std::string &iban, double balance) : iban(iban), balance(balance) {
    numOfAccounts++;
}

inline const std::string &account::getIban() const {
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

account::~account() {
    numOfAccounts--;
    std::cout << "account's destructor " << this->iban
              << ", numOfAccounts: "
              << numOfAccounts
              << std::endl;
}

account::account(const account &other) : iban(other.iban) {
    this->balance = other.balance;
    numOfAccounts++;
}

std::ostream &banking::operator<<(std::ostream &os, const account &account) {
    os << "account [ iban: " << account.getIban() << ", balance: " << account.getBalance() << " ]";
    return os;
}
