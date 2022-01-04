
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int largestBand( vector<int> arr) {
    int n = arr.size();
    unordered_set <int> s;
    int largestBand = 0;

    // data inside a set
    for (int x : arr) {
        s.insert(x);
    }

    for (auto element : arr) {
        int parent = element -1;
        if (s.find(parent) == s.end()) {
            int next_no = element + 1;
            int cnt = 1;
            while(s.find(next_no) != s.end()) {
                next_no++;
                cnt ++;
            }
            if (cnt > largestBand) {
                largestBand = cnt;
            }
        }

    }
    return largestBand;

}
int main () {

    vector<int> arr {1,2,3,4,5,6,7,8,9,15};
    cout << largestBand(arr) << endl;
    return 0;
}
