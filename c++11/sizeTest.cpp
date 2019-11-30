#include <iostream>
using namespace std;
class base {
    public:
    int i;
    char c;
    static int j;
};


int  main () {
    base b;
    cout << sizeof(b) <<endl;
    return 0;
}
