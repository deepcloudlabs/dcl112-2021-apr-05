#include <iostream>

using namespace std;

// abstract class
class animal {
    int legs;
public:
    animal(int legs) : legs(legs) {}

    int getLegs() const {
        return legs;
    }

    // concrete method
    virtual void walk() {
        cout << "Animal with "
             << legs
             << " legs is walking now..."
             << endl;
    }

    virtual void eat() = 0; // pure virtual method
};

// abstract class -> interface
struct pet {
    virtual void setName(const string &name) = 0;

    virtual const string &getName() const = 0;

    virtual void play() = 0;
};
// concrete -> animal -> override pure virtual method
struct spider : public animal {
    spider() : animal(8) {}

    void eat() override {
        cout << "spider is eating now..." << endl;
    }
};

// concrete -> animal, pet -> override pure virtual methods
class cat : public animal, public pet {
    string name;
public:
    cat() : animal(4), name("tekir") {}
    cat(const string &name) : animal(4), name(name) {}

    void eat() override {
        cout << name << " is eating now..." << endl ;
    }

    void setName(const string &name) override {
        this->name = name;
    }

    const string &getName() const override {
        return name;
    }

    void play() override {
        cout << name << " is playing now..." << endl ;
    }
};

class fish : public animal, public pet {
    string name;
public:
    fish(const string& name) : animal(0), name(name) {}

    void eat() override {
       cout << name << " is eating now..." << endl;
    }

    void setName(const string &name) override {
        this->name = name;
    }

    const string &getName() const override {
        return name;
    }

    void play() override {
       cout << name << " is playing now..." << endl;
    }

    void walk() override {
       cout << name << " is swimming now..." << endl;
    }
};
int main() {
    animal *animals[6]{
      new spider, new cat(), new spider,
      new fish("free willy"), new cat("garfield"),
      new spider
    };
    for (int i=0;i<6;++i){
        animal *p = animals[i];
        cout << typeid(*p).name() << endl;
        p->walk();
        p->eat();
        if (typeid(*p) != typeid(spider)){
            pet *q = dynamic_cast<pet*>(p);
            q->play();
        }
    }
    return 0;
}
