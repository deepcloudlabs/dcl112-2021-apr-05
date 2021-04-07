//
// Created by dcl on 4/6/2021.
//

#ifndef STUDY_COPYING_CHECKINGACCOUNT_H
#define STUDY_COPYING_CHECKINGACCOUNT_H

#include "account.h"

namespace banking {
    // public inheritance: account's public member --> CheckingAccount's public member
    // vs
    // private inheritance: account's public member --> CheckingAccount's private member
    class CheckingAccount : public account {
        double overdraftAmount;
    public:
        CheckingAccount(const std::string &iban, double balance, double overdraftAmount);

        inline double getOverdraftAmount() const;

        inline void setOverdraftAmount(double overdraftAmount);

        // overriding (inherited classes, the same signature)
        // vs
        // overloading (the same class, distinct signature)

        // c++11: override
        double withdraw(const double amount, bool withdrawAvailable=false) override;
    };
}


#endif //STUDY_COPYING_CHECKINGACCOUNT_H
