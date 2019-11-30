#include<stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int* a = new int[10];
    a[5] = 0;
    if (a[1])
        cout << a[3];
    return 0;
}
