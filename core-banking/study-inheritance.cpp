#include <iostream>
#include "account.h"
#include "checkingaccount.h"

using namespace banking;
using namespace std;

int main() {
    CheckingAccount acc1("tr1", 1000,500);
    cout << acc1 << endl;
    acc1.withdraw(1000);
    cout << acc1 << endl;
    acc1.withdraw(500);
    cout << acc1 << endl;
    acc1.withdraw(1);
    cout << acc1 << endl;
    return 0;
}