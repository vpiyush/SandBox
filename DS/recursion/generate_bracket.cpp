
// idea is to generate the bracket combination for given integer n.

#include<iostream>
using namespace std;

void generate_brackets(char *out, int n, int idx, int open, int close) {
    // base case
    // when we are end of the string combination i.e. we have used all open and close
    // brackets to form a sequence, mark the sequence with null character and print/store it.
    if (idx == 2*n) {
        out[idx] = '\0';
        cout << out << endl;
    }

    // rec case
    // option 1
    // we can always put an open brancket as long as the value is less than n
    if (open<n) {
        out[idx] = '(';
        generate_brackets(out, n, idx+1, open+1, close);
    }

    // option 2
    // close bracket can only be put if there are open brackets in preccding indexs are more than the close brackets til current
    // index
    if (close < open) {
        out[idx] = ')';
        generate_brackets(out, n, idx+1, open, close+1);
    }
}


int main() {
    int n;

    cin >> n;

    char out[1000];
    int idx = 0;
        generate_brackets(out, n, 0, 0, 0);
}
