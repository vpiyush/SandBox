#include <iostream>
using namespace std;

int findKey(int a[], int key, int index) {
  if (index < 0 ) {
    return -1;
  }
  if (a[0] == key) {
    return  0;
  }
  int i = findKey(a+1, key, index -1);
  if (i == -1) {
    return -1;
  } else {
    return i +1;
  }
}

int main() {
  int arr[] = {1,2,7,4,5,6,7,8,9};
  int key = 7;
  int n = sizeof arr/ sizeof arr[0];
  cout << findKey(arr, key, n) << endl;
}
