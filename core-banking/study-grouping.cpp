#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>
#include <parallel/numeric>
#include "checkingaccount.h"

using namespace banking;
using namespace std;

int main(){
    // coroutine (c++20)
    // generator function (c++20)
    // range abstraction -> STL -> filter/map/reduce -> Linux Shell Pipe ( | )  (c++20)
    vector<shared_ptr<account>> accounts;

    accounts.push_back(make_shared<account>(account("tr1", 1'000)));
    accounts.push_back(make_shared<CheckingAccount>(CheckingAccount("tr2", 2'000, 5000)));
    accounts.push_back(make_shared<account>(account("tr3", 3'000)));
    accounts.push_back(make_shared<CheckingAccount>(CheckingAccount("tr4", 5'000, 5000)));
    auto reducer = [](auto &group, auto acc) {
        auto accountType = typeid(*acc).name();
        cout << "accountType: " << accountType << std::endl;
        auto total = acc->getBalance();
        if( group.find(accountType) != group.end() )
            total += group[accountType];
        group[accountType] = total;
        return group;
    };
    auto result = accumulate(accounts.begin(), accounts.end(), map<std::string,double>(), reducer);
    for (auto const& [account_type, total_balance] : result){
        std::cout << account_type << " : " << total_balance << std::endl;
    }
}
