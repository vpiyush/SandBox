
#include <iostream>
#include <vector>
using namespace std;

// lcs for
// string s1 = "ABCD";
// string s2 = "ABEDG";
//  lcs value for above strings are "ABD"
//

//logic
//  f(s1, s2, i, j) =
//      if s1.length == 0 or s2.lenth == 0
//          return 0;
//      if (s1[i] == s2[j])
//          return 1+ lcs(s1, s2, i+1, j+1);
//      else
//          max of lcs (s1, 2 i+1, j) and lcs (s1, s2, i j+1)


//
int lcs(string s1, string s2, int i, int j, vector <vector<int> > dp) {

    // base case
    if (s1.length() == i or s2.length() == j) {
        return 0;
    }
    // dp
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (s1[i] == s2[j]) {
        return dp[i][j] = 1+ lcs(s1, s2, i+1, j+1, dp);
    }
    int lcs1 = lcs(s1, s2, i+1,j, dp);
    int lcs2 = lcs(s1, s2, i,j+1, dp);
    int ans = max(lcs1, lcs2);

    dp[i][j] = ans;

    return ans;
}

int main() {
    string s1 = "ABCD";
    string s2 = "ABEDG";

   vector< vector<int> > dp(s1.length(), vector<int>(s2.length(), -1));

    cout << lcs(s1, s2, 0, 0, dp) << endl;
    return 0;
}
