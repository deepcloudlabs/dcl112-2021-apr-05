#include <iostream>
#include "account.h"

using namespace banking;
using namespace std;

int main(){
    account acc1("tr1", 1000000);
    // account acc2 = acc1; // copy constructor!
    account acc3("tr2", 2000000);
    // acc3 = acc1 ; // assignment operator
    account acc4(1000);
    account acc5{1000};
    // ✘ Error: account acc6 = 1000; // due to explicit keyword

    return 0;
}