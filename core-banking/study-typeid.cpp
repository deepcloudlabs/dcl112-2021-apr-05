#include <iostream>

using namespace std;

struct ABC {
    virtual void fun(){
        cout << "A::fun" << endl;
    }
};

struct DEF: public ABC {
    void fun()  {
        cout << "B::fun" << endl;
    }
};

int main(){
    cout << "sizeof(ABC): " << sizeof(ABC) << endl;
    ABC *p = new ABC();
    ABC *q = new DEF();
    // object header: pointer -> virtual table
    // virtual table -> Run-Time Type Information
    p->fun();
    q->fun();
    cout << typeid(p).name() << endl;
    cout << typeid(q).name() << endl;
    cout << typeid(*p).name() << endl;
    cout << typeid(*q).name() << endl;
    const type_info& ti1 =  typeid(*p);
    const type_info& ti2 =  typeid(*q);
    if (typeid(*q) == typeid(ABC)){
        cout << "q points to ABC Object";
    } else if (typeid(*q) == typeid(DEF)){
        cout << "q points to DEF Object";
    }
    return 0;
}