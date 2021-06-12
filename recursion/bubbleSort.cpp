#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int a[], int n, int j) {
  if (n == 1) {
    return;
  }

  cout << n <<" " <<j << endl; 
  if (j == n-1) {
    return bubbleSort(a, n-1, 0);
  }

  if (a[j] > a[j+1]) {
    swap(a[j],a[j+1]);
  }
  
  return bubbleSort(a, n, j+1);
}


int main() {
  int arr[] = {1,2,7,4,5,6,7,8,9};
  int n = sizeof arr/ sizeof arr[0];
  bubbleSort(arr, n-1, 0);
  for (int i :arr) {
    cout << i << endl; 
  }
}
