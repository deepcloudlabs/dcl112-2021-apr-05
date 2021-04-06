#include "account.h"

using namespace banking;

int main(){
    // acc1 is a non-constant  object
    account acc1("tr1", 100000);
    acc1.getBalance(); // ✔ constant method!
    acc1.withdraw(25000); // ✔ non-constant method

    //acc2 is a CONSTANT object
    const account acc2("tr1", 100000);
    acc2.getBalance(); // ✔ constant method!
    // acc2.withdraw(25000); // ✘ Error: non-constant method

    return 0;
}
