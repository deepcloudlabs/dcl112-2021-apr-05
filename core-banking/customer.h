#ifndef STUDY_ABSTRACT_CLASS_CUSTOMER_H
#define STUDY_ABSTRACT_CLASS_CUSTOMER_H

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <memory>
#include <optional>
#include <ostream>

#include "account.h"
#include "checkingaccount.h"

using namespace std;

namespace banking {

    // entity -> identity -> tcKimlikNo
    class customer {
        const string tcKimlikNo;
        string fullname;
    protected:
        deque<shared_ptr<account>> accounts;
    public:
        customer() = delete;

        customer(const string &tcKimlikNo, const string &fullname);

        const string &getTcKimlikNo() const;

        const string &getFullname() const;

        void setFullname(const string &fullname);

        void addAccount(account &);

        template <class T>
        void addAccount(T &&acc) {
            this->accounts.push_back(std::make_shared<T>(acc));
        }

        std::map<std::string, double> groupByAccountType() const noexcept;

        optional<shared_ptr<banking::account>> findAccount1(const string &iban) const;

        optional<shared_ptr<banking::account>> findAccount2(const string &iban) const;

        optional<shared_ptr<banking::account>> findAccount(int index) const;

        double getTotalBalance() const;

        int getNumOfAccounts() const noexcept;

        friend ostream &operator<<(ostream &os, const customer &customer);

    };

    ostream &operator<<(ostream &os, const customer &customer);
}

#endif //STUDY_ABSTRACT_CLASS_CUSTOMER_H
