#include <iostream>
#include <thread>
using namespace std;

void func() {
    cout << "thread func " << endl;
}

int main () {
    std:thread t1(&func);
        t1.join();
        return 0;

}
