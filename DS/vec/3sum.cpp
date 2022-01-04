#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> pairsum(vector<int> arr, int n,  int pos, int sum) {
    int p1 = pos;
    int p2 = n-1;
    vector<vector<int>> result;
    while (p2>p1) {
        int s = arr[p2] + arr[p1];
        if (s == sum ) {
 //       cout << "found pairsum for " << sum << endl;
            result.push_back( {arr[p1], arr[p2]});
            while(p1<n-1 && arr[p1+1] == arr[p1]) {
                p1++;
            }
            while(p2>0 && arr[p2-1] == arr[p2]) {
                p2--;
            }
            p1++;
            p2--;
        } else if (s < sum) {
            p1++;
        } else {
            p2--;
        }
    }
    return result;
}
vector<vector<int> > triplets(vector<int> arr, int sum) {
    int n = arr.size();
  //  cout << "size of arr "  << n << endl;
    int p1 = 0;
    int p2 = n-1;
    vector<vector <int> > out;

    for (int i =0; i <n; i++) {
        int num = arr[i];
        if (i<n-1 && num == arr[i+1])
            continue;
        auto result = pairsum(arr, n, i+1, sum-num);
        if (!result.empty()) {
            for (auto res : result) {
                res.push_back(num);
                out.push_back(res);
            }
        }
    }
    return out;
}

int main() {
    vector<int> arr {1,2,3,4,5,6,7,8,9,15};
    int S=18;

    auto result = triplets(arr, S);
    for (auto res : result) {
        for (auto n : res)
            cout << n << " ";
        cout << endl;
    }
    return 0;
}
