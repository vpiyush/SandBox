#include <iostream>
using namespace std;
class Base {
    public:
        virtual void print() = 0;
};

class Der1: public Base {
    public:
     void print() {
         cout << "Der11" << endl;
     }
};

class Der2: public Base {
    public:
     void print() {
         cout << "Der12" << endl;
     }
};


class User {
    public:
    void print(Base *b1) {
        b1->print();
    }
};

int main () {
    Base *b1 = new Der1();
    User u1;
    u1.print(b1);
    b1 = new Der2();
    u1.print(b1);
    return 0;
}
