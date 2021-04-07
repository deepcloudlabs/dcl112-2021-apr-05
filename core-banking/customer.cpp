#include "customer.h"
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

void banking::customer::addAccount(account &acc) {
    this->accounts.push_back(std::make_shared<account>(acc));
}

void banking::customer::addAccount(account &&acc) {
    this->accounts.push_back(std::make_shared<account>(acc));
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

int banking::customer::getNumOfAccounts() const {
    return accounts.size();
}

ostream &banking::operator<<(ostream &os, const banking::customer &customer) {
    os << "tcKimlikNo: " << customer.tcKimlikNo << " fullname: " << customer.fullname;
    return os;
}
