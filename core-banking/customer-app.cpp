#include <iostream>
#include "customer.h"
#include "checkingaccount.h"

using namespace banking;
using namespace std;

int main(){
    customer jack("11111111110", "jack bauer");
    jack.addAccount(account("tr1", 1'000'000));
    jack.addAccount(CheckingAccount("tr2", 2'000'000, 5000));
    jack.addAccount(account("tr3", 3'000'000));
    jack.addAccount(CheckingAccount("tr4", 5'000'000, 5000));
    cout << "Number of accounts: " << jack.getNumOfAccounts() << endl;
    // cout << *(jack.findAccount1("tr1").value()) << endl;
    cout << "Total balance: " << jack.getTotalBalance() << std::endl ;
    for (auto const& [account_type, total_balance] : jack.groupByAccountType()){
        std::cout << account_type << " \t : " << total_balance << std::endl;
    }
    return 0;
}