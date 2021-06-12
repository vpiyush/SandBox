#include<iostream>
using namespace std;

// bottles to be sold one each year
// only last or first index can be sold
// price increases by the factor of years (each year price = price * year)

// topDown approach
int profit (int wines[], int i, int j, int y, int dp[][100] ) {
    // base case
    if (i>j) {
        return 0;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    // recursive case
    int op1 = wines[i]*y + profit(wines, i+1, j, y+1, dp); // ith index and rest of the array profit
    int op2 = wines[j]*y + profit(wines, i, j-1, y+1, dp);  // jth index and profit from rest of the array

    dp[i][j] = max(op1, op2);
    return dp[i][j];
}

// bottom up Apprach
int main() {
    int wines[] = {2,3,5,1,4};

    int y = 1; // start with first year
    int n = sizeof(wines)/sizeof wines[0];
    int dp[100][100] = {0};

    cout << "max profit " << profit(wines, 0, n-1, y, dp) << endl;


}

