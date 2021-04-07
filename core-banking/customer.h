#ifndef STUDY_ABSTRACT_CLASS_CUSTOMER_H
#define STUDY_ABSTRACT_CLASS_CUSTOMER_H

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <ostream>

#include "account.h"

using namespace std;

namespace banking {

// entity -> identity -> tcKimlikNo
    class customer {
        const string tcKimlikNo;
        string fullname;
    protected:
        vector<shared_ptr<account>> accounts;
    public:
        customer() = delete;

        customer(const string &tcKimlikNo, const string &fullname);

        const string &getTcKimlikNo() const;

        const string &getFullname() const;

        void setFullname(const string &fullname);

        void addAccount(account &);

        void addAccount(account &&);

        optional<shared_ptr<banking::account>> findAccount1(const string &iban) const;

        optional<shared_ptr<banking::account>> findAccount2(const string &iban) const;

        optional<shared_ptr<banking::account>> findAccount(int index) const;

        int getNumOfAccounts() const;

        friend ostream &operator<<(ostream &os, const customer &customer);

    };

    ostream &operator<<(ostream &os, const customer &customer);
}

#endif //STUDY_ABSTRACT_CLASS_CUSTOMER_H
