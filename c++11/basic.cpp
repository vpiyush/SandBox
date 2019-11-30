
#include <iostream>
#include <memory>
using namespace std;
class box {
    public:
    //default construct
    //destructor
    //copy constructor
    // constructor
    // mv constructor
    // mv assignement
    char *p;
    int j;

    box(int j, int k) {
        this->j = j;
        this->p = new char[10];
        memcpy(p, "abcd", 4);
    }

    box(const box& b) {
        this->p = new char[10];
        memcpy(p, b.p, 4);
        j = b.j;
    }

    box(box&& b) {
        this->p = b.p;
        this->j = b.j;
        b.p = nullptr;
    }

   box& operator =( const box&b2) {
        delete this->p;
        this->p = new char[10];
        memcpy(this->p, b2.p, 4);
        j = b2.j;
        return *this;
    }

   box& operator =( box&& b2) {
       if (this != &b2) {
        delete this->p;
        // no need to allocate new, use it from the source
        this->p = b2.p;
        this->j = b2.j;
        b2.p = nullptr;
       }
        return *this;
    }
    virtual ~box() {
        if (p != nullptr)
            delete p;
    }

    void print (int& i) {
        i = 12;
    }

    constexpr int sum (int i , int j) {
        int result = i + j;
        return result;
    }

};


int main () {
    const int i = 10;

    int result = 0;

    box b1(10, 15);
    box b2(11, 14);

    b1 = b2;
    box b3(b1);
    b2 = std::move(b1);
    return 0;
}
