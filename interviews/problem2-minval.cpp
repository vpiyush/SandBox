// Objectives:
// 1. is the implementation right
// 2. finish the porgram
// finish program to find min value
int minval(int *A, int n) {
  int currmin;
  for (int i=0; i<n; i++)
    if (A[i] < currmin)
      currmin = A[i];
  return currmin;
}
