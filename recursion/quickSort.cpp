#include <iostream>
#include <algorithm>
using namespace std;


int partition(int a[], int s, int e) {
  int i = s-1;
  int j = s;
  int pivot = a[e];
  for (j =s; j <=e-1; j++) {
    if (a[j] <= pivot) {
      i++;
      swap (a[i], a[j]);
    }
  }
  swap (a[i+1], a[e]);
  return i+1;
}
void quickSort(int a[], int s, int e) {
  //base case
  if (s >= e) {
    return;
  }
  // recursive code
  int pivot = partition(a, s, e);
  quickSort(a, s, pivot-1);
  quickSort(a, pivot+1, e);
  return;
}


int main() {
  int arr[] = {1,2,7,4,5,6,7,8,9};
  int n = sizeof arr/ sizeof arr[0];
  quickSort(arr, 0, n-1);
  for (int i :arr) {
    cout << i << endl; 
  }
}
