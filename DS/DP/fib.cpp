#include <iostream>
using namespace std;

int dp[1000] = {0};
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }

    if (dp[n] != 0) {
        return dp[n];
    }
    dp[n] = fib(n-2) + fib(n-1);
    return dp[n];
}
int fibBU(int n) {
    dp[1] = 1;
    for (int i=2; i<=n;i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << "fib number is "  << fib(n) << endl;
//    cout << "fib number BU "  << fibBU(n) << endl;
}
