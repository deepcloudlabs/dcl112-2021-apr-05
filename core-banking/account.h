#ifndef CORE_BANKING_ACCOUNT_H
#define CORE_BANKING_ACCOUNT_H

#include <string>
#include <ostream>

// ctrl + alt + l
namespace banking {
    // entity
    class account { // encapsulation : (iinformation hding) attribute + method
    private: // default
        std::string iban; // attribute -> identity
        double balance; // >= 0.0
    public:
        // constructor
        account(const std::string &iban, double balance = 0.0);

        // setter/getter
        inline const std::string &getIban() const; // read-only
        // const std::string * const getIban() const; // read-only

        double getBalance() const { // inlined
            return balance;
        }

        // business method
        bool deposit(const double amount);

        double withdraw(const double amount, bool withdrawAvailable=false);

        friend std::ostream &operator<<(std::ostream &os, const account &account);
    };
    std::ostream &operator<<(std::ostream &os, const account &account);
}


#endif //CORE_BANKING_ACCOUNT_H
