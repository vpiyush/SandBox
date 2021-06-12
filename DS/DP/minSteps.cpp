
#include <iostream>
using namespace std;

int dp[1000] = {0};

// number can be reduced by using either of these 3 operation
// if n%3 == 0 then n/3
// if n%2 == 0 then n/2
// n-1
int minStepsToOne(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int op1 = op2 = op3 = 0;
    if(n %3 == 0) {
        op1 = minStepsToOne(n/3);
    }else if(n %2 == 0) {
        op2 = minStepsToOne(n/2);
    } else {
        op3 = minStepsToOne(n-1);
    }


    dp[n] = min(op1, min(op2, op3)) + 1;
    return dp[n];
    //
}

int minStepsToOneBU(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i ++) {
        dp[i] = min(dp[n/3], min(dp[n/2], dp[n-1])) + 1;
    }
    return dp[n];
    //
}

int main() {
    int n;
    cin >> n;
    cout << "min Steps to one are "  << minStepsToOne(n) << endl;
}
