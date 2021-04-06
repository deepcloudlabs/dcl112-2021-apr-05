#include <iostream>
#include "account.h"
using namespace banking;

int main(){
    account acc1("tr2", 2000);
    account acc2 = {"tr2", 2000};
    account acc3 = {"tr2"};
    account acc4{"tr2"};
    account acc5= 100.1234; // casting operator

    // stack -> array
    account accounts[3]{
        {"tr1"},
        {"tr2", 2000},
        account("tr3", 3000)
    };
    account& tr2 = accounts[1];
    accounts[1].deposit(1000);
    tr2.withdraw(1500);
    std::cout << tr2 << std::endl;
    account *p = nullptr;
    p = new account[3]{
            {"tr4", 1000},
            {"tr5", 2000},
            {"tr6", 3000}
    };
    p[1].deposit(1000);
    (p+1)->withdraw(5000);
    (*(p+1)).withdraw(5000,true);
    std::cout << p[1] << std::endl;
    std::cout << *(p+1) << std::endl;
    std::cout << std::hex << p+0 << std::endl;
    std::cout << std::hex << p+1 << std::endl;
    std::cout << std::hex << p+2 << std::endl;
    std::cout << std::dec << sizeof(account) << std::endl;

    delete []p; // 3x ~account -> heap
    // 3x ~account -> stack
    return 0;
}
