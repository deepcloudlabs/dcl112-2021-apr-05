#include <iostream>
#include "account.h"
#include "checkingaccount.h"

using namespace banking;
using namespace std;

struct A {
    int d;
};
class B : public A {};
class C : public B {};
class D : private B {};
class E : public A {};
//  C -> B -> A <- E
//  D -*> B

int main(){
    A * a = new A; // ✔ B, ✔ C, ✘ D (private inheritance) , ✔ E
    a = new C;
    // Error: D uses private inheritance -> a = new D;
    a->d= 42;
    B * b = new B; // C, D
    E * e = static_cast<E*>(a); // Dangerous!!!

    account *p;
    p = new account("tr1", 100000); // ✔
    account *q;
    q = new CheckingAccount("tr2", 2000000, 10000); // ✔
    CheckingAccount *r;
    // Error: r = new account("tr3", 100000); // ✘
    return 0;
}
