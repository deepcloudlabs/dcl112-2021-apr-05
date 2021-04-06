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
    return 0;
}
