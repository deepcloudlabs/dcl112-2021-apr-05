#include <iostream>
#include "account.h"
using namespace  banking;
using namespace  std;

int main(){
    cout << account::getNumOfAccounts() << endl;

    account accounts[3]{
            {"tr1"},
            {"tr2", 2000},
            account("tr3", 3000)
    };

    cerr << account::getNumOfAccounts() << endl;
    account *p = nullptr;
    cerr << p->getBalance() << endl; // getBalance(p);
    cerr << p->getNumOfAccounts() << endl; // getNumOfAccounts()
    cerr << account::getNumOfAccounts() << endl; // getNumOfAccounts()

    return 0;
}
