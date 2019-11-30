#include<iostream>
using namespace std;
class base {
    private:
    int i;
    int j;

    virtual void print() {
        cout << "base Print" << endl;
    };
    public:
    virtual void invokePrint() {
        print();
        cout << "base print invocation" << endl;
    }
    base() {}
        base(int a, int b):i(a), j(b) {
        };
    virtual ~base() {
        cout << "base dest" << endl;
    }
};


class der : public base {
    public:
        der() {
        };
    void print() {
        cout << "der print" << endl;
    };
    virtual void invokePrint() {
        print();
        cout << "der print invocation" << endl;
    }
    ~der() {
        cout << "der dest" << endl;
    }
};

int main () {


    int i;
    i = 10;

    int j = 10;
    der *d1 =  new der();
    base *b1 =d1;
    b1->invokePrint();
    delete b1;
//    b1->changI();

    return 0;
}
