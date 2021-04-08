#ifndef CORE_BANKING_ACCOUNT_H
#define CORE_BANKING_ACCOUNT_H

#include <string>
#include <ostream>

// ctrl + alt + l
namespace banking {
    // entity
    struct account { // encapsulation : (information hiding) attribute + method
    private: // default access mode -> class
        const std::string iban; // attribute -> identity
        static int numOfAccounts; // declaration
    protected:
        double balance; // >= 0.0 -> optional
    public: // default access mode -> struct
        // constructor
        // explicit (c++11) -> disallows primitive conversion
        explicit account(double balance) : iban("tr42"), balance(balance) {
            numOfAccounts++;
        }

        account(const std::string &iban = "tr1", double balance = 0.0);

        account(const account &other);

        static int getNumOfAccounts() {
            return numOfAccounts;
        }

        // =delete deletes assignment operator
        account &operator=(const account &other) = delete;

        // setter/getter
        inline const std::string &getIban() const; // read-only

        double getBalance() const { // inlined
            return balance;
        }

        // business method
        virtual bool deposit(const double amount);

        virtual double withdrawAvailable(const double amount);
        virtual void withdraw(const double amount);

        virtual ~account();
        // friend std::ostream &operator<<(std::ostream &os, const account &account);
    };

    std::ostream &operator<<(std::ostream &os, const account &account);
}


#endif //CORE_BANKING_ACCOUNT_H
