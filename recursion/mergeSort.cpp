#include <iostream>
#include <algorithm>
using namespace std;

void merge(int a[], int s,  int e) {

  int mid = (s+e)/2;
  int s1 = s;
  int s2 = mid+1;
  int k[100] =  {};
  int count = s;

  while (s1 <= mid && s2 <= e) {
    if (a[s1] > a[s2]) {
      k[count++] = a[s2++];
    } else {
      k[count++] = a[s1++];
    }
  }
  while (s1 <= mid) {
    k[count++] = a[s1++];
  }
  while (s2 <= e) {
    k[count++] = a[s2++];
  }

  for (int i =s; i <=e; i++) {
    a[i] = k[i];
  }
  cout << endl;
  return;
}

void mergeSort(int a[], int s, int e) {
  if (s >= e) {
    cout << s << endl; 
    return;
  }
  int mid = (s+e)/2;
  mergeSort(a, s, mid);
  mergeSort(a, mid+1, e);
  // merge the sorted arrays
  merge(a, s,  e);

}


int main() {
  int arr[] = {1,2,7,4,5,6,7,8,9};
  int n = sizeof arr/ sizeof arr[0];
  mergeSort(arr, 0, n-1);
  for (int i :arr) {
    cout << i << endl; 
  }
}
