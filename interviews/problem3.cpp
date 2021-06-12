// predict the o/p of J
#include <iostream>
using namespace std;
int i = 5;
int j;

void do_something(const int& j) {
    j=14;
    return;
}
int foo(int j) {
  for (i=0; i<j; i++) do_something(j);
  return j;
}

void ineedj(void) {
  cout << "j is " << j << "\n";
}

int main() {
  int j;
  j = foo(i);
  ineedj();
  return 0;
}
