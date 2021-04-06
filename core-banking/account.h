#ifndef CORE_BANKING_ACCOUNT_H
#define CORE_BANKING_ACCOUNT_H

#include <string>

// entity
class account { // encapsulation : (information hiding) attribute + method
private: // default
    const std::string iban; // attribute -> identity
    double balance; // >= 0.0
public:
    // constructor
    account(const std::string &iban, double balance = 0.0);

    // setter/getter
    const std::string &getIban() const; // read-only

    double getBalance() const;

    // business method
    bool deposit(const double amount);
    bool withdraw(const double amount);

};


#endif //CORE_BANKING_ACCOUNT_H
