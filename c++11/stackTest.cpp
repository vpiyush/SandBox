#include <iostream>


void fun1 () {
    char a [2];
    memcpy(a, "abcdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 30);
}

void fun2 () {
    char a [5];
    memcpy(a, "abcd", 4);
    a[4] = '\0';
}

int main () {
    fun1();
    fun2();
    return 0;
}
