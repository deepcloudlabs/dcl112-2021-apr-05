#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include "customer.h"
#include "checkingaccount.h"

using namespace banking;
using namespace std;

int main(){
    customer jack("11111111110", "jack bauer");
    jack.addAccount(account("tr1", 1000000));
    jack.addAccount(CheckingAccount("tr2", 2000000, 5000));
    jack.addAccount(account("tr3", 3000000));
    cout << "Number of accounts: " << jack.getNumOfAccounts() << endl;
    cout << *(jack.findAccount2("tr1").value()) << endl;
    return 0;
}