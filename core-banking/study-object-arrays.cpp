#include <iostream>
#include "account.h"
using namespace banking;

int main(){
    // stack -> array
    account accounts[3]{
        {"tr1", 1000},
        {"tr2", 2000},
        {"tr3", 3000}
    };
    account& tr2 = accounts[1];
    accounts[1].deposit(1000);
    tr2.withdraw(1500);
    std::cout << tr2 << std::endl;
    account *p = nullptr;
    p = new account[3]{
            {"tr1", 1000},
            {"tr2", 2000},
            {"tr3", 3000}
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

    delete []p;
    return 0;
}
