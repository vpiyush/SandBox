
#include<iostream>
using namespace std;

int maxSumSubArray(int arr[], int n) {
    int max_so_far = 0;
    int currSum = 0;


    for (int i=0; i<n; i ++) {
        currSum += arr[i];
        if (currSum < 0) {
            currSum = 0;
        }
        max_so_far = max(max_so_far, currSum);
    }
    return max_so_far;
}

int main() {

    int arr[] = {1,2,3,4, -5, 2};
    cout << maxSumSubArray(arr, 6) << endl;
}
