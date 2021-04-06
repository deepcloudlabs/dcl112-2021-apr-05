#include <iostream>
#include "account.h"

using namespace banking;

// alt+enter
int main() {
    account acc("tr1", 10000); // stack object
    acc.deposit(5000);
    std::cout << acc.getBalance() << std::endl;
    acc.withdraw(7500,false);
    std::cout << acc.getBalance() << std::endl;
    acc.withdraw(7500,false);
    std::cout << acc.getBalance() << std::endl;
    acc.withdraw(100000, true);
    std::cout << acc.getBalance() << std::endl;
    std::cout << acc << std::endl;
    // Stack -> pointer: p -> Heap (account object)
    // Heap account object -> new -> pointer
    account *p = new account("tr1", 10000);
    p->deposit(5000); // (1)
    (*p).deposit(5000); // (2)
    p[0].deposit(5000); // (3)
    delete p;
    p = &acc; // p points Stack object
    p->deposit(5000); // acc.deposit(5000);
    // delete is not required!
    return 0;
}
