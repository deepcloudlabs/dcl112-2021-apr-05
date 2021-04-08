#include "customer.h"
#include "checkingaccount.h"
#include <parallel/algorithm>
#include <iostream>

banking::customer::customer(const string &tcKimlikNo, const string &fullname) : tcKimlikNo(tcKimlikNo),
                                                                                fullname(fullname) {}

const string &banking::customer::getTcKimlikNo() const {
    return tcKimlikNo;
}

const string &banking::customer::getFullname() const {
    return fullname;
}

void banking::customer::setFullname(const string &fullname) {
    customer::fullname = fullname;
}

optional<shared_ptr<banking::account>> banking::customer::findAccount1(const string &iban) const {
    // serial -> single cpu
    for (auto &acc : accounts) {
        if (acc->getIban() == iban)
            return optional<shared_ptr<account>>{acc};
    }
    return nullopt;
}

optional<shared_ptr<banking::account>> banking::customer::findAccount2(const string &iban) const {
    auto item = find_if(accounts.begin(), accounts.end(), [iban](auto &acc) {
        return acc->getIban() == iban;
    });
    if (item == accounts.end()) return nullopt;
    return optional<shared_ptr<account>>{*item};
}

optional<shared_ptr<banking::account>> banking::customer::findAccount(int index) const {
    if (accounts.empty()) return nullopt;
    if (index < 0 || index >= accounts.size()) return nullopt;
    return accounts[index];
}

double banking::customer::getTotalBalance() const {
    auto reducer = [](auto &total, auto &acc) {
        return total + acc->getBalance();
    };
    return std::accumulate(this->accounts.begin(), this->accounts.end(), double(), reducer);
}

int banking::customer::getNumOfAccounts() const noexcept {
    return accounts.size();
}

std::map<std::string, double> banking::customer::groupByAccountType() const noexcept {
    auto reducer = [](auto &group, auto acc) {
        auto key = typeid(*acc).name();
        cout << "key: " << key << std::endl;
        auto total = acc->getBalance();
        if( group.find(key) != group.end() )
            total += group[key];
        group[key] = total;
        return group;
    };
    return std::accumulate(this->accounts.begin(), this->accounts.end(),
                           map<std::string,double>(),
                           reducer);
}

ostream &banking::operator<<(ostream &os, const banking::customer &customer) {
    os << "tcKimlikNo: " << customer.tcKimlikNo << " fullname: " << customer.fullname;
    return os;
}
