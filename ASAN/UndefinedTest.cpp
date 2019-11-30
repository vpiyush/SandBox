#include <iostream>
#include <cstdio>
#include <unistd.h>
using namespace std;
int fun(int argc) {
  int *array = new int[100];
  delete [] array;
  return array[argc];  // BOOM
}
int main(int argc, char **argv) {
  int k = 0x7fffffff;
  k += argc;
  sleep(1);
  fun(argc);
  printf("recovered\n");
  return 0;
}
