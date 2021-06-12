#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// pick max number of activities, idea is to pick up the activities which finishes earlier
bool compare(pair<int, int> p1,pair <int, int> p2) {
  return p1.second < p2.second;
}

int main() {
  int t, n, s, e;

  cin >> t; // number of test cases
  vector <pair <int, int> > vec;

  while (t--) { 
    cin >> n;
    for (int i =0; i <n; i ++) {
      cin >> s>>e;
      vec.push_back(make_pair(s,e));

    }

    sort(vec.begin(), vec.end(), compare);
    // start picking activities
    int res = 1;
    int fin = vec[0].second;


    for (int i =1; i <n; i++) {
      if (vec[i].first >= fin) {
        fin = vec[i].second;
       res++;
      }
    }
    cout << res << endl;
  }
}
