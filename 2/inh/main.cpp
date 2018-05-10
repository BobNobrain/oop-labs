#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base()" << endl;
    }
    virtual ~Base() {
        cout << "~Base()" << endl;
    }
};

class Derived: public Base {
public:
    Derived() {
        cout << "Derived()" << endl;
    }
    virtual ~Derived() {
        cout << "~Derived()" << endl;
    }
};

int main(int argc, char const *argv[]) {
    Derived* d = new Derived();
    delete d;
    return 0;
}
