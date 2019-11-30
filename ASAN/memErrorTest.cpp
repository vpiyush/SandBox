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
	fun(argc);
	sleep(1);
	printf("recovered\n");
	return 0;
}
